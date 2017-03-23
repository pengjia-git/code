/*
 * You can mv a file to other fold when the file
 * has been opend and readed.
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  char *p="simplesection.c";
  int ret;
  int fd;
  char buf[128];
  fd=open(p,O_RDONLY);
  if(fd < 0)
    {
      printf("open file fail\n");
      return 0;
    }
  int size=read(fd,buf,127);
  buf[size]=0;
  printf("%s\n",buf);
  ret=rename(p,"../simplesection.c");
  if(ret < 0){
    printf("move file failed");
  }
  close(fd);
  return 0;
}
