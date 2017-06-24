#include <linux/init.h>
#include <linux/module.h>
#include <linux/sysfs.h>
#include <linux/wait.h>
#include <linux/string.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

wait_queue_head_t wait;
int wait_condition=0;
static size_t cooperate_show(struct kobject *kobj, struct kobj_attribute *attr,
        char *buf)
{
  const char *p="co_mutex read";
  wait_event(wait,wait_condition);
  sprintf(buf,p);
  return strlen(p);
}

static size_t cooperate_store(struct kobject *kobj, struct kobj_attribute
        *attr, const char *buf, size_t count)
{
  wait_condition=1;
  wake_up(&wait);
  return count;
}

static struct kobj_attribute cooperate_attribute =
    __ATTR(sys_test, 0777, cooperate_show, cooperate_store);

static struct attribute *cooperate_attr[] = {
    &cooperate_attribute.attr,
    NULL,
};

/* 定义一个group */
static struct attribute_group cooperate_group = {
     .name = "cooperate",
     .attrs = cooperate_attr,
};

static struct kobject *sys_kobj;
static int __init cooperate_init(void)
{
    int ret;
    printk("hello in create_sys_file_init\n");
    init_waitqueue_head(&wait);
    sys_kobj = kobject_create_and_add("cooperate_group", NULL);
    ret = sysfs_create_group(sys_kobj, &cooperate_group);
    if(ret) {
        printk(KERN_ERR "sysfs_create_group error\n");
        return -1;
    }
    return 0;
}

static void  __exit cooperate_exit(void)
{
    sysfs_remove_group(sys_kobj, &cooperate_group);
    printk( KERN_ERR "sysfs_remove_group\n");
}

module_init(cooperate_init);
module_exit(cooperate_exit);
MODULE_AUTHOR("1730548875@qq.com");
MODULE_DESCRIPTION("create sys file");
