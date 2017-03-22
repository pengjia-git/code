#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/semaphore.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");

static __init int hello_init(void)
{
  dev_t dev;
  if(alloc_chrdev_region(&dev,0,1,"writer") != 0){
    return;
  }
  printk(KERN_ALERT"hello world!\n");
  return 0;
}

static __exit void  hello_exit(void)
{
  //  struct semaphore a;
  //sema_init(&a,1);
  
  printk(KERN_ALERT"goodbye cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
