#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>

static struct cdev sig_dev;
static dev_t dev_id=0;

static int sig_open(struct inode *inode,struct file *filp)
{
	return 0;
}

static int sig_release(struct inode *inode,struct file *filp)
{
	return 0;
}

static int sig_fasync(int fd,struct file *filp,int mod)
{
	return 0;
}

static ssize_t sig_read(struct file *filp,char __user *buf,size_t count,loff_t * off)
{
	return 0;
}

static struct file_operations fop={
	.open=sig_open,
	.release=sig_release,
	.fasync=sig_fasync,
	.read=sig_read,
};

static int __init signal_init(void)
{
	int ret;	

	printk(KERN_WARNING"signal init\n");
	cdev_init(&sig_dev,&fop);
	ret=alloc_chrdev_region(&dev_id,0,1,"signal");
	if(ret != 0)
		return -1;
	cdev_add(&sig_dev,dev_id,1);
	return 0;
}
module_init(signal_init);

static void __exit signal_exit(void)
{
	printk(KERN_WARNING"signal exit\n");
	unregister_chrdev_region(dev_id,1);
	cdev_del(&sig_dev);
}
module_exit(signal_exit);

MODULE_LICENSE("GPL");

