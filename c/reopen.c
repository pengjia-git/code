#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

//off_t lseek(int fd, off_t offset, int whence);
//
int main()
{
	int size;
	int fd=open("test",O_RDWR);
	int fd1=open("test",O_RDWR);

	if(fd < 0)
		return -1;
	printf("fd=%d\n",fd);
	printf("fd1=%d\n",fd1);
	close(fd);
}
