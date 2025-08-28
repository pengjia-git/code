#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[100];
    int size;
    fd=open("/dev/globalmem",O_RDONLY);
    if(fd < 0)
        return -1;
    size=read(fd,buf,12);
    printf("size=%d\n",size);
    sleep(7);
    close(fd);
    printf("end\n");
    return 0;
}