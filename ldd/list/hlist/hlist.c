/*
This program will implement word finding function.
If user give a word,it will tell user weather it exist.
Init strings and word finding and others will interactive
with user using sysfs attribute files.

1.init hash array and attribute files.
2.depart words from string sentens.
3.fill library with words
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/string.h>
//#include <linux/sysfs.h>

static DEVICE__ATTR(searched_file,0666,NULL,NULL);
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

