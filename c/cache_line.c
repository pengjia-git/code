#include <stdio.h>
#include <stdlib.h>

int main(int argc,char ** argv)
{
	int i,j;
	int *p;
	int width=100,height=1024*1024;
	int sum;

	p=(int *)malloc(sizeof(int)*width*height);
	if(p == NULL){
		printf("malloc error\n");	
		return -1;
	}
	    for(j=0;j<height;j++)
		for(i=0;i<width;i++)
			p[i*height+j]=32;
	printf("sum=%d\n",sum);
	return 0;
}
