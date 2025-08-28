#include <stdio.h>


#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif

int foo1(int c)
{
	int count=0;
	for(int i=0;i<c;i++)
		count+=i*3/2;		
	return count;
	
}

int foo2(int c)
{
	printf("c is %d\n",c);
	return 0;
}

int main(int argc,char *argv[])
{
	if(unlikely(argc <3))	
		foo1(123);
	else
		foo2(1);
	return 0;
}
