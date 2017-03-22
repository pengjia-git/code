/*===============================================================
*   Copyright (C) 2015 All rights reserved.
*
*   File  ：sys_1.c
*   Author：Gavin (gavinlu1015@gmail.com)
*   Date  ：2015-04-22
*   Remark：基于linux3.10
*
================================================================*/
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
/* 读sys文件，例如cat sys_test */
static size_t sys_test_show(struct kobject *kobj, struct kobj_attribute *attr,
        char *buf)
{
  wait_event_interruptible_timeout(wait,flag !=0,HZ*5);
  return snprintf(buf, 10, "%s", "1234567890\n");
}

/* 写入sys文件,例如echo xxx sys_test*/
static size_t sys_test_store(struct kobject *kobj, struct kobj_attribute
        *attr, const char *buf, size_t count)
{
  flag=1;
 wake_up_interruptible(&wait);
    return 0;
}

/* 定义创建sys文件的属性 */
static struct kobj_attribute sys_file_attribute =
    __ATTR(sys_test, 0777, sys_test_show, sys_test_store);

static struct attribute *sys_test_attr[] = {
    &sys_file_attribute.attr,
    NULL,
};

/* 定义一个group */
static struct attribute_group sys_file_test_group = {
     .name = "sys_file_test2",
     .attrs = sys_test_attr,
};


/* /fs/sysfs/group.c */
static int __init create_sys_file_init(void)
{
    int ret;
    printk("hello in create_sys_file_init\n");
        init_waitqueue_head(&wait);
    sys_kobj = kobject_create_and_add("sys_test_group1", NULL);
    ret = sysfs_create_group(sys_kobj, &sys_file_test_group);
    if(ret) {
        printk(KERN_ERR "sysfs_create_group error\n");
        return -1;
    }
    printk(KERN_ERR "sysfs_create_group ok\n");
    //    sysfs_remove_group(sys_kobj, &sys_file_test_group);
    printk( KERN_ERR "sysfs_remove_group\n");

    return 0;
}

static void  __exit create_sys_file_exit(void)
{
    sysfs_remove_group(sys_kobj, &sys_file_test_group);
    printk( KERN_ERR "sysfs_remove_group\n");
}

module_init(create_sys_file_init);
module_exit(create_sys_file_exit);
MODULE_AUTHOR("gavinlu1990@gmail.com");
MODULE_DESCRIPTION("create sys file");
