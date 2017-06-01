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
  INIT_LIST_HEAD(&p->list);

  if(p->name == NULL)
    return -ENOMEM;
  if(info == NULL){
	info=p;
	return 0;
   }

  list_add(&p->list,&info->list);

  return 0;
}

void print_list(struct usb_info *p)
{
	struct usb_info *pos;
	list_for_each_entry(pos,&p->list,list){
		printk(KERN_ALERT"%d %s\n",pos->pid,pos->name);
	}
	
}
MODULE_LICENSE("GPL");

static int list_init(void)
{
	printk(KERN_ALERT"list world!\n");
	register_usb(1,"usb_1");
	register_usb(2,"usb_2");
	register_usb(3,"usb_3");
	register_usb(4,"usb_4");
	print_list(info);
	return 0;
}

static int list_exit(void)
{
	printk(KERN_ALERT"goodbye cruel world\n");
	return 0;
}

module_init(list_init);
module_exit(list_exit);
