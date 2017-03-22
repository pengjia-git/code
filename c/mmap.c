#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
  int fd=open("123",O_RDWR);
  int i;
  char *p=NULL;
  p=mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  
  for(i=0;i<1024/4;i++)
    sprintf(p+i*4,"%4d",i);
  //  printf("%s",p);
  munmap(p,1024);
  close(fd);
  return 0;
}
