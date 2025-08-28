#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
    int fd;
    char *str1="123456\n";
    char *str2="7890ab\n";
    char *str;
    int num=atoi(argv[2]);
    printf("argc=%d\n",argc);
    if(argc != 3)
        return -1;

    if(atoi(argv[1]) == 0)
        str=str1;
    else
        str=str2;
    printf("str =%s\n",str); 
    fd=open("test.txt",O_CREAT|O_RDWR,0660);
    if(fd<0){
        printf("%s\n",strerror(errno));
        return -1;
    }
    while(num--) {
        lseek(fd,0,SEEK_END);
        write(fd,str,strlen(str));
    }
    close(fd);
    return 0;
}