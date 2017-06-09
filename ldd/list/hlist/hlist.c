/*
  This program will implement word finding function.
  If user give a word,it will tell user weather it exist.
  Init strings and word finding and others will interactive
  with user using sysfs attribute files.

  1.init hash array and attribute files.
  2.depart words from string sentens.
  3.fill library with words
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/device.h>//DEVICE_ATTR defined in this file
#include "hlist.h"
static struct kobject *sys_kobj;

static struct search *search;

static ssize_t show_searched_file(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
  return snprintf(buf, search->file_len, "%s",search->searched_file);
}

static ssize_t store_searched_file(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf,
				   size_t count)
{
  char *p;
  int len;

  if(search == NULL || search->searched_file == NULL)
    return 0;
  strncpy(search->searched_file,buf,PAGE_SIZE);
  search->file_len=count;

  do{
    p=split(&len);
     
  }while(p);
  return count;
}

static DEVICE_ATTR(searched_file,0666,show_searched_file,store_searched_file);

static struct attribute *search_attributes[]={
  &dev_attr_searched_file.attr,
  NULL,
};

static struct attribute_group search_group={
  .attrs=search_attributes,
};

char * split(int *strlen)
{
  char *star,*new_pos;
  int len;
  if(search->pos == NULL)
    search->pos=search->searched_file;
  star=search->pos;
  new_pos=strchr(star,' ');
  if(new_pos == NULL){
    search->pos=NULL;
    return NULL;
  }

  len=new_pos-star;
  *strlen=len;
  return new_pos;
}

static int hlist_init(void)
{
  int ret;
  search=kzalloc(sizeof(struct search),GFP_KERNEL);
  search->searched_file=kmalloc(PAGE_SIZE,GFP_KERNEL);
  sys_kobj=kobject_create_and_add("search",NULL);
  if(sys_kobj == NULL){
    printk("create kobj failed\n");
    return -1;
  }
  ret=sysfs_create_group(sys_kobj,&search_group);
  //sysfs_create_file(sys_kobj,&dev_attr_searched_file);
  if(ret != 0)
    printk("create group failed\n");
  return 0;
}

static void hlist_exit(void)
{
  sysfs_remove_group(sys_kobj,&search_group);
  //sysfs_create_file(sys_kobj,&dev_attr_searched_file);
  kobject_put(sys_kobj);
  kfree(search->searched_file);
  kfree(search);
}

MODULE_LICENSE("GPL");
module_init(hlist_init);
module_exit(hlist_exit);
