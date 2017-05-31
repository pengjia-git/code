/*
  练习内核list的使用。
  要求：列表按注册时的名字排列。
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/string.h>
struct usb_info{
	int pid;
	char *name;
	struct list_head list;
};

struct usb_info *info;

int register_usb(int pid,char *name)
{
  struct usb_info *p;

  p=kmalloc(sizeof(struct usb_info),GFP_KERNEL);

  if(p == NULL)
    return -ENOMEM;

  p->pid=pid;
  p->name=kstrdup(name,GFP_KERNEL);

  if(p->name == NULL)
    return -ENOMEM;
  
  list_add(p,info);
  return 0;
}

MODULE_LICENSE("GPL");

static int list_init(void)
{
	printk(KERN_ALERT"list world!\n");
	register_usb(1,"usb_1");
	register_usb(2,"usb_2");
	register_usb(3,"usb_3");
	
	return 0;
}

static int list_exit(void)
{
	printk(KERN_ALERT"goodbye cruel world\n");
	return 0;
}

module_init(list_init);
module_exit(list_exit);
