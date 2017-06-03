#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
MODULE_LICENSE("GPL");


#define MAX_USER_LEN 32  
#define MAX_PAS_LEN 32  
#define MAX_SERVER_LEN 1024  
  
   
typedef struct server_detect_ftp  
{  
  struct list_head list;  
  char server[MAX_SERVER_LEN];  
  int port;  
  char username[MAX_USER_LEN];  
  char password[MAX_PAS_LEN];  
}server_detect_ftp_t;

static int hello_init(void)
{
  LIST_HEAD(head);
  server_detect_ftp_t ftp_link;  
  server_detect_ftp_t ftp_link1;  
  server_detect_ftp_t *entry;  
  
  INIT_LIST_HEAD(&head);//初始化头部  
  strcpy(ftp_link.server,"www.163.com");  
  ftp_link.port=34;  
  strcpy(ftp_link.username,"good1");  
  strcpy(ftp_link.password,"good");  
  
  strcpy(ftp_link1.server,"www.163.com");  
  ftp_link1.port=34;  
  strcpy(ftp_link1.username,"good2");  
  strcpy(ftp_link1.password,"good");  
  
  list_add_tail(&ftp_link.list,&head);  
  list_add_tail(&ftp_link1.list,&head);//添加链表  
  list_del(&ftp_link.list);
  list_for_each_entry(entry,&head,list){
    printk(KERN_ALERT"hello world! %s\n",entry->username);
  }
  list_del(&ftp_link1.list);
  if(list_empty(&head))
    printk("empty\n");
  else
    printk("not empty\n");
  return 0;
}

static int hello_exit(void)
{
  printk(KERN_ALERT"goodbye cruel world\n");
  return 0;
}

module_init(hello_init);
module_exit(hello_exit);
