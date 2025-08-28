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
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/pid_namespace.h>

static int __init hello_init(void)
{
	struct task_struct *task;
	struct pid *pid_struct;
	struct mm_struct *mm;
	struct vm_area_struct *vma;
	// unsigned long addr;
	printk(KERN_INFO "Hello World enter\n");
	pid_struct = find_get_pid(1281);
	if (!pid_struct)
	{
		printk(KERN_ERR "Process with PID  not found\n");
		return -EINVAL;
	}

	// Get the task_struct from the PID struct
	task = get_pid_task(pid_struct, PIDTYPE_PID);
	if (!task)
	{
		return -EINVAL;
	}
	mm = task->active_mm;
	vma = find_vma(mm, 0x001e9000);
	if (vma == NULL)
	{
		printk(KERN_INFO "VMA not found\n");
	}
	else
	{
		printk(KERN_INFO "VMA found start=0x%lx\n", vma->vm_start);
	}
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
