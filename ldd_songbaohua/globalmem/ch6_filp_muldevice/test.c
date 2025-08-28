#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char *buf="global mem test\n";
    int size;
    fd=open("/dev/globalmem0",O_RDWR);
    if(fd < 0)
        return -1;
    size=write(fd,buf,strlen(buf));
    printf("size=%d\n",size);
    // sleep(7);
    close(fd);
    printf("end\n");
    return 0;
}