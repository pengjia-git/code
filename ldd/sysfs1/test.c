#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
int fd;
 char buf[4096];
 int size;

 fd=open(argv[1],O_RDONLY);
 while(1){
   size=read(fd,buf,4096);
   printf("size=%d\n",size);
 }
 return 0;
}
