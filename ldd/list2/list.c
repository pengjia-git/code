#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>

struct usb_info{
	int pid;
	char *name;
	struct list_head list;
};

struct usb_info *info;

int register_usb(int pid,char *name)
{
	
}

MODULE_LICENSE("GPL");

static int list_init(void)
{
	printk(KERN_ALERT"list world!\n");
	return 0;
}

static int list_exit(void)
{
	printk(KERN_ALERT"goodbye cruel world\n");
	return 0;
}

module_init(list_init);
module_exit(list_exit);
