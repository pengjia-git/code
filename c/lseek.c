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
	int fd=open("test",O_CREAT,O_RDWR);

	if(fd < 0)
		return -1;
	lseek(fd,100,SEEK_SET);
	size=write(fd,"pengjia",7);
	printf("size=%d\n",size);
	close(fd);
}
