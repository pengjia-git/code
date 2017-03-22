#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>

//const char *global_symbol="global symbol";
void print_global(void)
{
  printk(KERN_ALERT"%s\n","print_global");
}
static int hello_init(void)
{
	printk(KERN_ALERT"module symbol\n");
	return 0;
}

static int hello_exit(void)
{
	printk(KERN_ALERT"module symbol exit\n");
	return 0;
}

module_init(hello_init);
module_exit(hello_exit);

EXPORT_SYMBOL_GPL(print_global);
MODULE_LICENSE("GPL");
