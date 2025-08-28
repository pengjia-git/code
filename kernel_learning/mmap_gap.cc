#include <stdio.h>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>

void * reg_map(void * start_addr,int len)
{
	void *p;
	p=mmap(start_addr,len,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,0,0);	
	return p;
	
}

int mmap_gap()
{
	int step=10*1024*1024;
	int gap=1*1024*1024;
	extern int  _end;
	void *start=&_end;
	int count=0;
	while(1)
	{
		count++;
		start+=gap;

		void *p=reg_map(start,step);
		printf("start=%p,p=%p\n",start,p);

		if(p==MAP_FAILED)
		{
			printf("count=%d\n",count);
			break;
		}

		int *pi=(int *)p;
		for(int i=0;i<1000;i++)
			pi[i]=i;
	}
	return 0;
}


int main()
{
	extern int  _end;
	printf("end=%p",&_end);
	mmap_gap();
	sleep(100);
	return 0;
}
