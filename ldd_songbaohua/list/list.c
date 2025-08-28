/*
 * a simple kernel module: hello
 *
 * Copyright (C) 2014 Barry Song  (baohua@kernel.org)
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/cache.h>
#include <linux/list.h>

struct task_entry{
	struct list_head head;
	int num;
};

static LIST_HEAD(my_tasks);

int task_entry_init(struct task_entry *p)
{
	INIT_LIST_HEAD(&p->head);
	p->num=0;
	return 0;
}

void test(void)
{
	int i;
	struct task_entry list[30];
	struct task_entry *p;
	struct list_head *head;
	for(i=0;i<30;i++){
		p=list+i;
		task_entry_init(p);
		p->num=i;
		list_add_tail(&p->head,&my_tasks);
		
	}

	list_for_each_entry(p,&my_tasks,head){
		// p=container_of(head,struct task_entry,head);
		printk("num=%d\n",p->num);
	}
}

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World enter %d\n",L1_CACHE_BYTES);
	test();
	return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Hello World exit\n");
}
module_exit(hello_exit);

MODULE_AUTHOR("Barry Song <21cnbao@gmail.com>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello World Module");
MODULE_ALIAS("a simplest module");
