#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/timer.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
struct mutex_test{
  dev_t dev_id;
  struct timer_list timer;
  struct cdev cdev;
  char buf[512];
};

struct mutex_test mutex_test;

ssize_t cap_data_read(struct file * file,char __user * data,size_t count,loff_t * pos)
{
  printk("cap_data_read\n");
  copy_to_user(data,"jia",4);
  return 4;
}

int mutex_test_open(struct inode * inode,struct file * fp)
{
  printk("mutex_test_open\n");
  return 0;
}

int mutex_test_close(struct inode * inode,struct file * fp)
{
  printk("mutex_test_close\n");
  return 0;
}

struct file_operations mutex_fops ={
  .owner=THIS_MODULE,
  .read =cap_data_read,
  .open =mutex_test_open,
  .release = mutex_test_close,
  
};

void cap_dat(unsigned long data)
{
  static int i=0;
  mutex_test.timer.expires=jiffies+HZ;
  add_timer(&mutex_test.timer);
  printk("get one data i=%d\n",i++);
  
}

static void dev_init(struct mutex_test * dev)
{

  cdev_init(&dev->cdev,&mutex_fops);
  cdev_add(&dev->cdev,dev->dev_id,1);
}
static int mutex_test_init(void)
{
  int ret;
  
  printk(KERN_ALERT"mutex_test_init!\n");
  //ret=register_chrdev_region(255,1,"mutex");
  ret=alloc_chrdev_region(&mutex_test.dev_id,0,1,"mutex");
  printk("dev_id=%d major=%d,minor=%d\n",mutex_test.dev_id,
	 MAJOR(mutex_test.dev_id),MINOR(mutex_test.dev_id));

  init_timer(&mutex_test.timer);
  mutex_test.timer.expires=jiffies+HZ;
  mutex_test.timer.function=cap_dat;

  add_timer(&mutex_test.timer);
  dev_init(&mutex_test);
  return 0;
}

static void mutex_test_exit(void)
{
  del_timer(&mutex_test.timer);
  unregister_chrdev_region(mutex_test.dev_id,1);
  printk(KERN_ALERT"mutex_test_exit\n");
}

module_init(mutex_test_init);
module_exit(mutex_test_exit);
