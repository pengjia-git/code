#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/kref.h>

#define DEVICE_NAME "refcount_demo"
#define CLASS_NAME  "refdemo"

struct my_device {
    struct kref refcount;  // 引用计数
    int data;              // 模拟数据
};

static struct my_device *global_dev;
static struct class *refclass;
static struct device *refdevice;
static int major_number;

/* 释放设备对象的回调 */
static void my_device_release(struct kref *ref)
{
    struct my_device *dev = container_of(ref, struct my_device, refcount);
    pr_info("my_device_release: 释放设备\n");
    kfree(dev);
}

/* 设备打开 */
static int my_open(struct inode *inode, struct file *file)
{
    pr_info("my_open: 设备被打开\n");
    kref_get(&global_dev->refcount);  // 增加引用计数
    file->private_data = global_dev;
    return 0;
}

/* 设备关闭 */
static int my_release(struct inode *inode, struct file *file)
{
    pr_info("my_release: 设备被关闭\n");
    kref_put(&global_dev->refcount, my_device_release); // 递减引用计数
    return 0;
}

/* 设备操作集 */
static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = my_open,
    .release = my_release,
};

/* 模块初始化 */
static int __init refcount_init(void)
{
    pr_info("refcount_init: 加载模块\n");

    /* 分配设备结构体 */
    global_dev = kmalloc(sizeof(struct my_device), GFP_KERNEL);
    if (!global_dev)
        return -ENOMEM;

    /* 初始化引用计数 */
    kref_init(&global_dev->refcount);
    global_dev->data = 42;

    /* 注册字符设备 */
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        kfree(global_dev);
        pr_err("无法注册设备\n");
        return major_number;
    }

    /* 创建 class 和 device */
    refclass = class_create(CLASS_NAME);
    if (IS_ERR(refclass)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        kfree(global_dev);
        return PTR_ERR(refclass);
    }

    refdevice = device_create(refclass, NULL, MKDEV(major_number, 0), NULL, DEVICE_NAME);
    if (IS_ERR(refdevice)) {
        class_destroy(refclass);
        unregister_chrdev(major_number, DEVICE_NAME);
        kfree(global_dev);
        return PTR_ERR(refdevice);
    }

    pr_info("设备注册成功: /dev/%s\n", DEVICE_NAME);
    return 0;
}

/* 模块卸载 */
static void __exit refcount_exit(void)
{
    pr_info("refcount_exit: 卸载模块\n");

    /* 删除设备和类 */
    device_destroy(refclass, MKDEV(major_number, 0));
    class_destroy(refclass);
    unregister_chrdev(major_number, DEVICE_NAME);

    /* 释放设备 */
    kref_put(&global_dev->refcount, my_device_release);
}

module_init(refcount_init);
module_exit(refcount_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("示例: 使用 kref 进行引用计数管理");
MODULE_VERSION("1.0");

