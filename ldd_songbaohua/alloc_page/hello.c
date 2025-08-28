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
#include <linux/gfp.h>
#include <linux/mm.h>

static void test(void)
{
    struct page *p;
    void *addr;
    int i;

    printk("hello world\n");
    p=alloc_pages(GFP_KERNEL,0);
    if(p== NULL)
        printk("alloc page failed\n");
    else
        printk("alloc page success\n");
    addr=page_address(p);
    printk("page addr=%p\n",addr);
    printk("page addr 1=%lx\n",(unsigned long)(addr));

    for(i=0;i<4096;i++)
        ((char*)addr)[i]='a';
}

static int __init hello_init(void)
{
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
