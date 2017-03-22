//#define __KERNEL__ //这样才能使用list.h，具体请看list.h  
//#include "list.h" /*由于我的机器上没有list.h,所以我拷贝了一个，如果你机器上有，应//该是加
#include <linux/list.h>*/  
#include <stdio.h>   
#include <string.h>  
  
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
  
int main(void)  
{  
    struct list_head head;//头部  
    server_detect_ftp_t ftp_link;  
    server_detect_ftp_t ftp_link1;  
    server_detect_ftp_t *entry;  
    struct list_head *p;  
    INIT_LIST_HEAD(&head);//初始化头部  
    strcpy(ftp_link.server,"www.163.com");  
    ftp_link.port=34;  
    strcpy(ftp_link.username,"good");  
    strcpy(ftp_link.password,"good");  
  
    strcpy(ftp_link1.server,"www.163.com");  
    ftp_link1.port=34;  
    strcpy(ftp_link1.username,"good");  
    strcpy(ftp_link1.password,"good");  
  
    INIT_LIST_HEAD(&head);  
  
    list_add(&ftp_link.list,&head);  
    list_add(&ftp_link1.list,&head);//添加链表  
    list_del(&ftp_link1.list);//删除链表  
    list_for_each(p,&head)//遍历  
    {  
        entry=list_entry(p,struct server_detect_ftp,list);//读取某个值  
  
        printf("%s\n",entry->username);  
    }  
  
    return 0;  
} 
