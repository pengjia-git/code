#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv)
{
    int i,fd;
    char c;

    fd=open("/home/jia/1Mfile",O_RDONLY);
    if(fd < 0)
        return -1;

    for(i=0;i<1000*1000;i++)
        read(fd,&c,1);
    close(fd);
    printf("test end\n");
    return 0;
}