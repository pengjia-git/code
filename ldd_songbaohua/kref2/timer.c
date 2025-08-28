#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/kref.h>

#define TIMER_INTERVAL (HZ *10) // 定时器间隔：1秒（HZ = 100~1000，取决于内核配置）

static struct timer_list my_timer;
static char *p=NULL;
static struct kref ref;


static void release(struct kref *ref)
{
	pr_info("release resource\n");
	kfree(p);
}

/* 定时器回调函数 */
void my_timer_callback(struct timer_list *t)
{
    pr_info("内核定时器触发！\n");
    p[99]=3;
    kref_put(&ref,release);
}

/* 模块加载时初始化定时器 */
static int __init my_timer_init(void)
{
    pr_info("定时器驱动初始化...\n");
    p=kmalloc(100,GFP_KERNEL);
    memset(p,0,100);
    kref_init(&ref);
    

    /* 初始化定时器 */
    timer_setup(&my_timer, my_timer_callback, 0);

    /* 设置定时器超时时间 */
    kref_get(&ref);
    mod_timer(&my_timer, jiffies + TIMER_INTERVAL);

    return 0;
}

/* 模块卸载时删除定时器 */
static void __exit my_timer_exit(void)
{
    pr_info("定时器驱动卸载，删除定时器...\n");
    //del_timer(&my_timer);
    kref_put(&ref,release);
}

module_init(my_timer_init);
module_exit(my_timer_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Linux 内核定时器示例");

