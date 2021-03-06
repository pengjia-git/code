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

static ssize_t show_statistic(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
int i;
char *pos=buf;
struct hlist_head *head;
struct hlist_node *node;
struct search_node *ser_node;
head=search->head;
for(i=0;i<256;i++){
head=&search->head[i];
printk("%d ",i);
hlist_for_each_entry(ser_node,node,head,node){
printk("%s ****",ser_node->str);
}
printk("\n");
}
return 0;
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
int hash_val;
    char *test;
struct search_node *node;
struct hlist_head *head;
    p=split(&len);
    if(p== NULL)
      break;
    if(len == 0)
      continue;
    test=kzalloc(len+1,GFP_KERNEL);
node=kmalloc(sizeof(*node),GFP_KERNEL);
    memcpy(test,p,len);
hash_val=get_hash_of_string(test);
if(hash_val == -1)
  continue;
node->str=test;
head=&search->head[hash_val];
INIT_HLIST_NODE(&node->node);
hlist_add_head(&node->node,head);
    printk("%s\n",test);
  }while(p);
  return count;
}

int get_hash_of_string(const char *p)
{
int len,count=0;
int i;
if(p == NULL)
  return -1;
len=strlen(p);
for(i=0;i<len;i++)
  count+=p[i];
return count%256;
}


static DEVICE_ATTR(searched_file,0666,show_searched_file,store_searched_file);
static DEVICE_ATTR(statistic,0666,show_statistic,NULL);

static struct attribute *search_attributes[]={
  &dev_attr_searched_file.attr,
    &dev_attr_statistic.attr,
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
  search->pos=new_pos+1;
  return star;
}

static int hlist_init(void)
{
  int ret;
int i;
struct hlist_head *p;
  search=kzalloc(sizeof(struct search),GFP_KERNEL);
  search->searched_file=kmalloc(PAGE_SIZE,GFP_KERNEL);
p=search->head;
for(i=0;i<256;i++)
  INIT_HLIST_HEAD(&p[i]);
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
