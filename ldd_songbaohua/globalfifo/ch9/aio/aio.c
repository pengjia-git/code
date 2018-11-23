#include <stdio.h>
#include <aio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 1024
int main(int argc,char * argv[])
{
	int fd,size;
	int ret;
	struct aiocb my_aiocb;

	fd=open("aio.c",O_RDONLY);
	if(fd < 0 )
		return -1;
	memset(&my_aiocb,0,sizeof(my_aiocb));
	
	my_aiocb.aio_buf=malloc(BUF_SIZE+1);
	if(my_aiocb.aio_buf == NULL)
		return -2;
	memset(my_aiocb.aio_buf,0,BUF_SIZE);
	my_aiocb.aio_fildes = fd;
	my_aiocb.aio_nbytes = BUF_SIZE;
	my_aiocb.aio_offset = 0;
	
	ret=aio_read(&my_aiocb);
	sleep(1);	
	printf("%s\n",(char *)my_aiocb.aio_buf);
	printf("%d\n",aio_return(&my_aiocb));
	printf("no error\n");
	return 0;
}
