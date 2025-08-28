#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/sysfs.h>

#define SYSFS_DIR "kernel"
#define SYSFS_FILE "per_cpu_file"
#define COUNT_MAX_SIZE 20

static int count = 0;
DEFINE_PER_CPU(int, cpu_run_count);
// sysfs读文件的回调函数
static ssize_t per_cpu_file_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf) {
    printk(KERN_INFO "cpu id= %d cpu_run_count=%d count= %d\n", smp_processor_id(), ++get_cpu_var(cpu_run_count), ++count);
    put_cpu_var(cpu_run_count);
    return sprintf(buf, "%d\n", count);
}

// sysfs写文件的回调函数
static ssize_t per_cpu_file_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count) {
    int value;

    if (count > COUNT_MAX_SIZE)
        return -EINVAL;

    if (kstrtoint(buf, 10, &value))
        return -EINVAL;

    // 写入新的值
    count = value;

    return count;
}

static struct kobj_attribute per_cpu_file_attribute = __ATTR(per_cpu_file, 0660, per_cpu_file_show, per_cpu_file_store);

static struct attribute *attrs[] = {
    &per_cpu_file_attribute.attr,
    NULL,
};

static struct attribute_group attr_group = {
    .attrs = attrs,
};

static struct kobject *my_kobject;

static int __init per_cpu_file_init(void) {
    int retval;

    my_kobject = kobject_create_and_add(SYSFS_DIR, kernel_kobj);
    if (!my_kobject) {
        pr_err("Failed to create /sys/kernel/%s directory\n", SYSFS_DIR);
        return -ENOMEM;
    }

    retval = sysfs_create_group(my_kobject, &attr_group);
    if (retval) {
        kobject_put(my_kobject);
        pr_err("Failed to create /sys/kernel/%s/%s file\n", SYSFS_DIR, SYSFS_FILE);
        return retval;
    }

    pr_info("Per-CPU File Module Loaded\n");

    return 0;
}

static void __exit per_cpu_file_exit(void) {
    sysfs_remove_group(my_kobject, &attr_group);
    kobject_put(my_kobject);
    pr_info("Per-CPU File Module Unloaded\n");
}

module_init(per_cpu_file_init);
module_exit(per_cpu_file_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module with a per-CPU file in sysfs");
MODULE_VERSION("1.0");
