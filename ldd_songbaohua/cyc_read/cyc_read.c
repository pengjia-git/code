#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/wait.h>
#include <linux/timer.h>

static dev_t cr_id;
static struct cdev *cr_devp;
DECLARE_WAIT_QUEUE_HEAD(cr_wait_head);

static int cr_open(struct inode *inode,struct file *filp)
{
	return 0;
}

static int cr_release(struct inode *inode,struct file *filp)
{
	return 0;
}

static ssize_t cr_read(struct file *filp,char __user *buf,size_t size,loff_t *off)
{
	int count=8;
	DECLARE_WAITQUEUE(wait,current);	
	add_wait_queue(&cr_wait_head,&wait);
	set_current_state(TASK_INTERRUPTIBLE);
	schedule();
	copy_to_user(buf,"cyc_read",count);
	filp->f_pos+=count;

	*off+=count;
	remove_wait_queue(&cr_wait_head,&wait);
	return count;
}

static struct file_operations cr_fops={
	.owner=THIS_MODULE,
	.open=cr_open,
	.release = cr_release,
	.read=cr_read,
};

void cr_timer_handle(struct timer_list *timer)
{
	printk(KERN_WARNING"cr_timer_handle\n");
	mod_timer(timer,jiffies+100);
	wake_up_interruptible(&cr_wait_head);
}

DEFINE_TIMER(cr_timer,cr_timer_handle);


static int __init cyc_read_init(void)
{
	int ret;

	ret=alloc_chrdev_region(&cr_id,0,1,"cyc_read");
	if(ret != 0)
		return -1;

	cr_devp=cdev_alloc();	
	if(cr_devp == NULL)
		return -1;
	cdev_init(cr_devp,&cr_fops);
	cr_devp->owner=THIS_MODULE;
	ret=cdev_add(cr_devp,cr_id,1);
	if(ret != 0)
		return -1;
	
	mod_timer(&cr_timer,jiffies+1000);
	printk(KERN_WARNING"cyc read init\n");

	return 0;
}
module_init(cyc_read_init);


static void __exit cyc_read_exit(void)
{
	del_timer(&cr_timer);
	cdev_del(cr_devp);
	unregister_chrdev_region(cr_id,1);
	printk(KERN_WARNING"cyc read exit\n");
}
module_exit(cyc_read_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("pengjia");
