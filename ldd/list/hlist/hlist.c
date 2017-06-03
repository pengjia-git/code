#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/string.h>

static int hlist_init(void)
{
  return 0;
}

static void hlist_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init(hlist_init);
module_exit(hlist_exit);

