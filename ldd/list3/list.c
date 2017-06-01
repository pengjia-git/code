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
  struct list_head *insert_pos;
  p=kmalloc(sizeof(struct usb_info),GFP_KERNEL);

  if(p == NULL)
    return -ENOMEM;

  p->pid=pid;
  p->name=kstrdup(name,GFP_KERNEL);

  if(p->name == NULL)
    return -ENOMEM;
  list_add_tail(&p->list,&usb_list);
  return 0;

  if(list_empty(&usb_list)){
    printk(KERN_ALERT"list is emtpy\n");
  }
  printk(KERN_ALERT"++++\n");
  list_for_each_entry_continue(pos,&usb_list,list){
    printk(KERN_ALERT"pos->name=%s,p->name=%s\n",pos->name,p->name);
    if(pos->name && (strcmp(p->name,pos->name) <0 )){
      printk(KERN_ALERT"cannont go here\n");

      break;
    }
  }
  printk(KERN_ALERT"---------------\n");
  list_prev_entry(pos,list);
  printk(KERN_ALERT"pos->name=%s\n",pos->name);
  list_add(&p->list,&pos->list);
  return 0;
}

void print_list(struct list_head *p)
{
  struct usb_info *pos;
  //printk(KERN_ALERT"%d %s\n",p->pid,p->name);
  
  list_for_each_entry_continue(pos,p,list){
    printk(KERN_ALERT"%d %s\n",pos->pid,pos->name);
  }
	
}
MODULE_LICENSE("GPL");

static int list_init(void)
{
  register_usb(1,"usb_1");
  register_usb(2,"usb_2");
  register_usb(3,"usb_3");
  register_usb(4,"usb_4");
  print_list(&usb_list);
  return 0;
}

static int list_exit(void)
{
  return 0;
}

module_init(list_init);
module_exit(list_exit);
