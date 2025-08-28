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

#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/sched/mm.h>
#include <linux/moduleparam.h>
#include <linux/io.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>

#define POINT_SIZE 64*1024
static int **point;
static int __init hello_init(void)
{
	int i;

	printk(KERN_INFO "Hello World enter\n");
	point = kmalloc(POINT_SIZE*sizeof(void *), GFP_KERNEL);
	for(i=0;i<POINT_SIZE;i++) {
		point[i] =(int *)kmalloc(16, GFP_KERNEL);
	}
	return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
	int i;
	for(i=0;i<POINT_SIZE;i++) {
		kfree(point[i]);
	}
	kfree(point);
	printk(KERN_INFO "Hello World exit\n");
}
module_exit(hello_exit);

MODULE_AUTHOR("Barry Song <21cnbao@gmail.com>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello World Module");
MODULE_ALIAS("a simplest module");
