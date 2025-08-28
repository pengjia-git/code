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
#include <linux/fs.h>
#include <linux/list.h>
#include <linux/ext2_fs.h>

static int __init hello_init(void)
{
	struct file_system_type *fsys;
	struct hlist_node *hnode;
	struct super_block *sb;
	struct ext4_sb_info *sbi;

	fsys=get_fs_type("ext4");
	if(fsys){
		printk("get file system ext4 ok\n");
	}
	hnode=fsys->fs_supers.first;
	sb=hlist_entry(hnode,struct super_block,s_instances);	
	if(sb == NULL)
		return -1;
	printk("s_blocksize=%d\n",sb->s_blocksize);
	sbi=EXT4_SB(sb);
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
