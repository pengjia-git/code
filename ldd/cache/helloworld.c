#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h> 

MODULE_LICENSE("GPL");
static char *p;
static struct kmem_cache * cache;
static char *p1,*p2;
static int hello_init(void)
{
  
  printk(KERN_ALERT"hello world!\n");
  cache=kmem_cache_create("jia_cache",512,0,SLAB_HWCACHE_ALIGN,NULL);
  if(cache == NULL){
    printk(KERN_ALERT"kmem_cache_create fail\n");
    return -1;
  }
  p1=kmem_cache_alloc(cache,GFP_KERNEL);
  p2=kmem_cache_alloc(cache,GFP_KERNEL);
  printk(KERN_DEBUG"P1=%p,p2=%p\n",p1,p2);
  return 0;
}

static void hello_exit(void)
{
  printk(KERN_ALERT"goodbye cruel world\n");
  kmem_cache_free(cache,p1);
  kmem_cache_free(cache,p2);
  kmem_cache_destroy(cache);
  //  kfree(p);
  //return 0;
}

module_init(hello_init);
module_exit(hello_exit);
