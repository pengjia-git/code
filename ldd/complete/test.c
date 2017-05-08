#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main()
{
  int fd=open("/dev/complete",O_RDONLY);
  printf("%s\n",strerror(errno));
  return 0;
}
