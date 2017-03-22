#include <linux/init.h>
#include <linux/module.h>
#include "module_symbol.h"

//const char *global_symbol="global symbol";

static int hello_init(void)
{
	printk(KERN_ALERT"quote module symbol\n");
	//	printk(KERN_ALERT"123%s\n",global_symbol);
	print_global();
	return 0;
}

static int hello_exit(void)
{
	printk(KERN_ALERT"module symbol exit\n");
	return 0;
}

module_init(hello_init);
module_exit(hello_exit);


MODULE_LICENSE("GPL");
