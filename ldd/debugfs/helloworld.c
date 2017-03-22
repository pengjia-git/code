#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/debugfs.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");


#define UVC_DEBUGFS_BUF_SIZE	1024
int a;
struct uvc_debugfs_buffer {
	size_t count;
	char data[UVC_DEBUGFS_BUF_SIZE];
};

static int uvc_debugfs_stats_open(struct inode *inode, struct file *file)
{
	struct uvc_streaming *stream = inode->i_private;
	struct uvc_debugfs_buffer *buf;
	int i;

	buf = kmalloc(sizeof(*buf), GFP_KERNEL);
	if (buf == NULL)
		return -ENOMEM;

//	buf->count = uvc_video_stats_dump(stream, buf->data, sizeof(buf->data));
	buf->count=100;
	for(i=0;i<100;i++)
		buf->data[i]='j';
	file->private_data = buf;
	return 0;
}

static ssize_t uvc_debugfs_stats_read(struct file *file, char __user *user_buf,
				      size_t nbytes, loff_t *ppos)
{
	struct uvc_debugfs_buffer *buf = file->private_data;

	return simple_read_from_buffer(user_buf, nbytes, ppos, buf->data,
				       buf->count);
}

static int uvc_debugfs_stats_release(struct inode *inode, struct file *file)
{
	kfree(file->private_data);
	file->private_data = NULL;

	return 0;
}

static const struct file_operations uvc_debugfs_stats_fops = {
	.owner = THIS_MODULE,
	.open = uvc_debugfs_stats_open,
	.llseek = no_llseek,
	.read = uvc_debugfs_stats_read,
	.release = uvc_debugfs_stats_release,
};


struct dentry *dent;
static int hello_init(void)
{

	printk(KERN_ALERT"hello world!\n");
//	debugfs_create_dir("debugfs_jia",NULL);
	dent=debugfs_create_dir("jia",NULL);
	debugfs_create_u8("a", 0666, dent, &a);
	return 0;
}

static int hello_exit(void)
{
	printk(KERN_ALERT"goodbye cruel world\n");
	debugfs_remove_recursive(dent);
	return 0;
}

module_init(hello_init);
module_exit(hello_exit);
