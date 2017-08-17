#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/sysfs.h>
#include <linux/wait.h>
#include <linux/sched.h>

#include <linux/time.h>
#include <linux/timer.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/types.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

static struct kobject *sys_kobj;
static wait_queue_head_t wait;
int flag=0;

static size_t sys_test_show(struct kobject *kobj, struct kobj_attribute *attr,
			    char *buf)
{
  wait_event_interruptible(wait,flag !=0);
  return snprintf(buf, 10, "%s", "1234567890\n");
}

static size_t sys_test_store(struct kobject *kobj, struct kobj_attribute
			     *attr, const char *buf, size_t count)
{
  flag=1;
  wake_up_interruptible(&wait);
  return count;
}
static struct bin_attribute bin_attr={
  .attr = {
    .name="bin_attr",
    .mode=S_IRUGO|S_IWUSR,
  },
  .size=10,
  .read=sys_test_show,
  .write=sys_test_store,
};

static int __init create_sys_file_init(void)
{
  int ret;
  printk("hello in create_sys_file_init\n");
  init_waitqueue_head(&wait);
  sys_kobj = kobject_create_and_add("sys_test_group1", NULL);
  if(sys_kobj == NULL){
    printk("sys create fail\n");
    return -1;
  }
  ret=sysfs_create_bin_file(sys_kobj,&bin_attr);
  if(ret) {
    printk(KERN_ERR "sysfs_create_group error\n");
    return -1;
  }
  return 0;
}

static void  __exit create_sys_file_exit(void)
{
  sysfs_remove_bin_file(sys_kobj,&bin_attr);
}

module_init(create_sys_file_init);
module_exit(create_sys_file_exit);
MODULE_AUTHOR("gavinlu1990@gmail.com");
MODULE_DESCRIPTION("create sys file");
