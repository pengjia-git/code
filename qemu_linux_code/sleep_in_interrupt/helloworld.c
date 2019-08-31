#include <linux/init.h>
#include <linux/module.h>
//#include <linux/list.h>
#include <linux/timer.h>
#include <linux/delay.h>
MODULE_LICENSE("GPL");
static struct timer_list timer;

void timer_handler(struct timer_list * handler)
{
  printk(KERN_ERR"pengjia timer_handler\n");
  msleep(100);
}

static int hello_init(void)
{
	printk(KERN_ALERT"hello world!\n");
  timer.expires=jiffies+(3*HZ);
  timer.function=timer_handler;
  add_timer(&timer);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT"goodbye cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
