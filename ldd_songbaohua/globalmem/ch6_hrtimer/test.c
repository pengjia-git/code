#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
    int fd;
    char *path="/dev/globalmem";
    char arr[180]={0};
    char *buf="pengjia";

    printf("%p\n",buf);
    fd=open(path,O_RDWR);
    if(fd<0)
        return -1;

    write(fd,buf,strlen(buf));
    write(fd,arr,1);
    close(fd);
    return 0;
    
}