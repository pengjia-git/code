#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  char *path = "/dev/refcount_demo";
  int fd = open(path, O_RDONLY);
  if (fd < 0)
  {
    printf("open fail\n");
    return -1;
  }
  while (1)
    ;
  close(fd);
  return 0;
}
