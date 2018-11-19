#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 0xff0
static char *filename="/dev/globalmem";
static int count=1000000;

int check_mem(void)
{
	int fd;
	char *buf;
	int size,i;
	int count=0;

	buf=(char *)malloc(BUF_SIZE);
	memset(buf,0,BUF_SIZE);
	
	fd=open(filename,O_RDONLY);
	if(fd <= 0)
		return -1;

	while(count--){
		
		size=read(fd,buf,BUF_SIZE);
		mdelay(1);
		if(size != BUF_SIZE)
			return -1;
		for(i=1;i<BUF_SIZE;i++)
			if(buf[i] != buf[0]){
				printf("warming count=%d\n",count++);
				buf[BUF_SIZE-1]=0;
				printf("%s\n",buf);
				break;
			}
		lseek(fd,0,SEEK_SET);
	}
	close(fd);
	free(buf);

	return 0;

}


int write_mem(char c)
{
	int fd;
	char *buf;
	int size,i;

	buf=(char *)malloc(BUF_SIZE);
	memset(buf,c,BUF_SIZE);
	
	fd=open(filename,O_WRONLY);
	if(fd <= 0)
		return -1;
		
	while(count--){
		
		size=write(fd,buf,BUF_SIZE);
		if(size != BUF_SIZE)
			return -1;
		lseek(fd,0,SEEK_SET);
	}
	close(fd);
	free(buf);

	return 0;


}

int main(int argc,char *argv[])
{
 	if(argc == 1)	
		check_mem();
	else
		write_mem(argv[1][0]);
	return 0;
}
