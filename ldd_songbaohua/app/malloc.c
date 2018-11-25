#include <stdio.h>
#include <stdlib.h>


int main()
{
	int malloc_size=1024*1000;
	int i;
	char *p;

	p=(char *)malloc(malloc_size);
	p[0]=3;

	for(i=0;i<malloc_size;i++)
		if(p[i] !=0)
			printf("error\n");
	return 0;
}
