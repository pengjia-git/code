#include <linux/module.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/kthread.h>
MODULE_LICENSE("GPL");

int my_function(void * argc)
{
    printk("in the kernel thread function! \n");
    printk("the current pid is:%d\n", current->pid);     //显示当前进程的进程号
    printk("out the kernel thread function\n");
    return 0;
}

static int __init prepare_to_wait_init(void)
{
    /*局部变量定义*/
    struct task_struct * result, *result1;
    int   wait_queue_num=0;
    wait_queue_head_t head;
    wait_queue_t data, data1, *curr, *next;
    printk("into prepare_to_wait_init.\n");
    /*创建两个新进程*/
    result=kthread_create_on_node(my_function, NULL, -1, "prepare_to_wait");
    result1=kthread_create_on_node(my_function, NULL, -1, "prepare_to_wait1");
    wake_up_process(result);
    wake_up_process(result1);
    init_waitqueue_head(&head);            //初始化等待队列头指针
    init_waitqueue_entry(&data, result); //用新进程初始化等待队列元素
    data.task_list.next=&data.task_list; // 初始化等待队列元素的next字段
    printk("the state of the current thread is:%ld\n", current->state);
                                           //显示当前进程的状态

    prepare_to_wait(&head, &data,130);     //将新进程加入等待队列，并更改当前进程的状态
    printk("the state of the current thread is:%ld\n", current->state);
                                           //显示当前进程的状态

    init_waitqueue_entry(&data1, result1); // 用新进程初始化等待队列元素
    prepare_to_wait(&head, &data1,1);      //将新进程加入等待队列，并更改当前进程的状态
    printk("the state of the current thread is:%ld\n", current->state);
                                           //显示当前进程的状态

    /*循环显示等待队列中的等待元素的信息*/
    list_for_each_entry_safe(curr, next, &(head.task_list), task_list)
    {
        wait_queue_num++;                  //累加等待队列中的元素个数

        /*显示等待队列中当前等待元素的flags字段的值*/
        printk("the flag value of the current data of the waitqueue is:%d\n", curr->flags);
        /*显示等待队列中当前等待元素对应的进程的PID值*/
        printk("the pid value of the current data of the waitqueue is:%d\n", ((struct task_struct *)(curr->private))->pid);
    }
    printk("the value of the wait_queue_num is :%d\n", wait_queue_num);
                                          // 显示当前等待队列中的等待元素的个数

    data1.task_list.next=&data1.task_list; // 初始化等待队列元素的next字段
    prepare_to_wait(&head, &data1,1);     //将新进程加入等待队列，并更改当前进程的状态
    wait_queue_num=0;

    /*循环显示等待队列中的等待元素的信息*/
    list_for_each_entry_safe(curr, next, &(head.task_list), task_list)
    {
        wait_queue_num++;                  //累加等待队列中的元素个数
        /*显示等待队列中当前等待元素的flags字段的值*/
        printk("the flag value of the current data of the waitqueue is:%d\n", curr->flags);

        /*显示等待队列中当前等待元素对应的进程的PID值*/
        printk("the pid value of the current data of the waitqueue is:%d\n", ((struct task_struct *)(curr->private))->pid);
    }
    printk("the value of the wait_queue_num is :%d\n", wait_queue_num);
                                          // 显示当前等待队列中的等待元素的个数

    /*显示函数kernel_thread( )的返回结果*/
    printk("the pid of new thread is :%d\n", result->pid);
    printk("the pid of new thread1 is :%d\n", result1->pid);
    printk("the current pid is:%d\n", current->pid); //显示当前进程的PID值
    printk("out prepare_to_wait_init.\n");
    return 0;
}


static void __exit prepare_to_wait_exit(void)
            {
                printk("Goodbye prepare_to_wait\n");
            }

  module_init(prepare_to_wait_init);
            module_exit(prepare_to_wait_exit);

            module_init(prepare_to_wait_init);
            module_exit(prepare_to_wait_exit);          