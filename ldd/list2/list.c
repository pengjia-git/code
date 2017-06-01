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

static LIST_HEAD(usb_list);

int register_usb(int pid,char *name)
{
  struct usb_info *p,*pos;

  p=kmalloc(sizeof(struct usb_info),GFP_KERNEL);

  if(p == NULL)
    return -ENOMEM;

  p->pid=pid;
  p->name=kstrdup(name,GFP_KERNEL);

  if(p->name == NULL)
    return -ENOMEM;
  if(list_empty(&usb_list)){
    list_add(&p->list,&usb_list);
    return 0;
  }

  list_for_each_entry(pos,&usb_list,list){
    if(pos->name && (strcmp(p->name,pos->name) <0 )){
      list_add_tail(&p->list,&(pos->list));
      return 0;
    }
  }
  list_add_tail(&p->list,&usb_list);
  return 0;
}

void print_list(struct list_head *p)
{
  struct usb_info *pos;
  list_for_each_entry(pos,p,list){
    printk(KERN_ALERT"%d %s\n",pos->pid,pos->name);
  }	
}


static int list_init(void)
{
  register_usb(2,"uvc");
  register_usb(4,"usb");
  register_usb(3,"adb");
  register_usb(1,"mnt");

  print_list(&usb_list);

  return 0;
}

static void list_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init(list_init);
module_exit(list_exit);

