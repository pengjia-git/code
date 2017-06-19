#include <linux/init.h>
#include <linux/module.h>
#include <linux/workqueue.h>

MODULE_LICENSE("GPL");
struct workqueue_struct *queue;
struct work_struct work;
void work_fun(struct work_struct * work )
{
  printk("work_fun\n");
}

static int workqueue_init(void)
{
  printk(KERN_ALERT"hello world!\n");
  INIT_WORK(&work,work_fun);
  schedule_work(&work);
  queue=create_workqueue("jia_workqueue");
  printk("workqueue init complete\n");
  return 0;
}

static void workqueue_exit(void)
{
  destroy_workqueue(queue);
  printk(KERN_ALERT"goodbye cruel world\n");
}

module_init(workqueue_init);
module_exit(workqueue_exit);
