#include <stdio.h>

int sum(int a,int b)
{
	int ret;
	char *p=NULL;

	printf("%s,%d %c\n",__func__,__LINE__,*p);
	ret=a*b;

	return ret;
}

int add(int a,int b)
{
	printf("%s,%d\n",__func__,__LINE__);
	sum(a,a+b);
	return 0;
}

int main(int argc,char *argv[])
{
	add(3,8);
	return 0;
}
