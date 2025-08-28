/*
 * a simple kernel module: hello
 *
 * Copyright (C) 2014 Barry Song  (baohua@kernel.org)
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/cache.h>

#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/sched/mm.h>
#include <linux/moduleparam.h>
#include <linux/io.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
struct cache_test
{
    int a;
    int flag;
    char name[10];
};

static struct kmem_cache * cache_test_p;

void test(void)
{
    struct cache_test* test = kmem_cache_alloc(cache_test_p, GFP_KERNEL);
    printk("kmem_cache_alloc address=%lx\n",(unsigned long)test);
    kmem_cache_free(cache_test_p, test);
}

// 示例的内核线程执行函数
int my_thread_function(void *data)
{
    struct task_struct *my_current;
    // 线程的实际执行逻辑
    while(1){
        //打印当前进程pid
       my_current=get_current(); 
       printk("pid=%d\n",my_current->pid);
        test();
        msleep(1000);
    }
    return 0;
}

void test2(void)
{
    pr_info("in test2 ,it may sleep\n");
    might_sleep_if(1);
    msleep(1000);

}


static int __init hello_init(void)
{
    struct task_struct *my_thread;
    spinlock_t lock;
    spin_lock_init(&lock);
    cache_test_p=KMEM_CACHE(cache_test, SLAB_PANIC);
    // 创建内核线程，指定执行函数和传递的数据
    my_thread = kthread_create(my_thread_function, NULL, "my_thread");

    if (my_thread)
    {
        // 启动内核线程
        wake_up_process(my_thread);
    }
    else
    {
        printk(KERN_INFO "Failed to create kernel thread\n");
        return -ENOMEM; // 错误处理
    }
    spin_lock(&lock);
    test2();
    spin_unlock(&lock);
    printk(KERN_INFO "Kernel thread created successfully\n");
    return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Hello World exit\n");
}
module_exit(hello_exit);

MODULE_AUTHOR("Barry Song <21cnbao@gmail.com>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello World Module");
MODULE_ALIAS("a simplest module");
