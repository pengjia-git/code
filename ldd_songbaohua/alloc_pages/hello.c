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

static int pid=0;
static unsigned long addr=0;
module_param(pid, int, S_IRUGO); 
module_param(addr, long, S_IRUGO); 
// ...

struct task_struct *get_task_struct_by_pid(int pid) {
    struct pid *pid_struct;
    struct task_struct *task;

    // 根据 PID 获取 pid_struct 结构体
    pid_struct = find_get_pid(pid);

    if (pid_struct == NULL) {
        pr_err("Failed to get PID structure\n");
        return NULL;
    }

    // 根据 pid_struct 获取 task_struct 结构体
    task = get_pid_task(pid_struct, PIDTYPE_PID);

    if (task == NULL) {
        pr_err("Failed to get task structure\n");
        return NULL;
    }

    return task;
}

// 使用示例
void example_usage(int pid) {
    struct task_struct *task = get_task_struct_by_pid(pid);
	struct mm_struct *mm ;//= task->mm;
	//long long *p=NULL;
    int *p;
    int * vir_p;
	//int i;
       pgd_t *pgd;
    //unsigned long addr;
    p4d_t *p4d;
    pud_t *pud;
    pmd_t *pmd;
    pte_t *pte;
	

    if (task != NULL) {
        // 在这里可以使用 task 指针进行进一步的操作
        pr_info("Task command: %s\n", task->comm);
        // ...
		mm = task->mm;
		//printk("pgd is %llx\n",(long long)(*(mm->pgd)));
		//printk("pgd is %llx\n",(long long)(mm->pgd));
		#if 0
		p=(long long *)(mm->pgd);
		p=(long long *)(*p);
		for(i=0;i<4096;i++)
			if((long long)(p[i]) != 0)
				printk("pengjia pgd index=%d is %llx\n",i,(long long)(p[i]));

		#endif
        pgd=pgd_offset(mm,addr);
        pr_info("1 Page Directory Entry Value: %llx\n", pgd_val(*pgd)& PHYSICAL_PAGE_MASK);
        p4d=p4d_offset(pgd,addr);

        pr_info("2 p4d=%llx\n",(long long)p4d);
        pud=pud_offset(p4d, addr);
        pmd=pmd_offset(pud, addr);
        pte=pte_offset_kernel(pmd, addr);
        //pr_info("pte val=%lx\n",pte_val(*pte));
       
       
        pr_info("pysical addr=%llx\n",PFN_PHYS(pte_pfn(*pte)) );
        p= (int *)(PFN_PHYS(pte_pfn(*pte)) +0xa54);
        vir_p=(int *)phys_to_virt(p);
        *vir_p=99;
         #if 0
        for (addr = 0; addr < TASK_SIZE; addr += PGDIR_SIZE) {
        pud_t *pud_entry = pud_offset(pgd, addr);

        // 打印地址和页表项内容
        pr_info("Virtual Address: %lx, PUD Value: %lx\n", addr, pud_val(*pud_entry));
         }
         #endif
    } else {
        pr_err("Task not found for PID %d\n", pid);
    }
}


static int __init hello_init(void)
{
	//printk(KERN_INFO "Hello World 1 enter %d %d,%d\n",L1_CACHE_BYTES,sizeof(long),sizeof(long long));
	printk("point size is %ld\n",sizeof(void *));
// no head file
//	BUG_ON(1); 
	example_usage(pid);
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
