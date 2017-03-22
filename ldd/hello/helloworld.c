#include <linux/init.h>
#include <linux/module.h>
//#include <linux/list.h>
MODULE_LICENSE("GPL");

static int hello_init(void)
{
	printk(KERN_ALERT"hello world!\n");
	return 0;
}

static int hello_exit(void)
{
	printk(KERN_ALERT"goodbye cruel world\n");
	return 0;
}

module_init(hello_init);
module_exit(hello_exit);
