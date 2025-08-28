#include <stdio.h>
#define likely(x)       __builtin_expect((x), 1)  
#define unlikely(x)     __builtin_expect((x), 0)
int sub_fun(int a,int b);

int add_fun(int a,int b)
{
	printf("in add_fun\n");
	int tmp;
	tmp=a+b;
	return tmp;
}

int main(int argc,char *argv[])
{
	long long c=0x12322312ababcdcd;
	int a=0x12341234;
	int b=0x5678bead;
	int d=3;
	int f1=100;
	int f2=-100;
	unsigned int f3=1;
	unsigned int f4=-1;
	int e1=-1;
	int e2;
	int h1=0x12321234;
	printf("pengjia add_fun=%d\n",a+b);
	
	e2=(e1<<12)+f3;
	printf("e2=%x\n",e2);
	printf("=%x\n",h1&0xfffffffe);
	if(unlikely(d >23))
		add_fun(a,b);
	else
		sub_fun(a,b);
	
	return 0;
}


int sub_fun(int a,int b)
{
	printf("in sub_fun\n");
	int tmp;
	tmp=a-b;
	return tmp;
}

