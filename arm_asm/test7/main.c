#include <stdio.h>

void my_atomic_add(unsigned long val,void *p)
{
	unsigned long tmp;
	unsigned long tmp1;
	int result;
	asm volatile(
		"1:ldxr %0,%2\n"
		"add %0,%0,%3\n"
		"stxr %w1,%0,%2\n"
		"cbnz %w1,1b\n"
		:"+r" (tmp),"+r"(result),"+Q"(*(unsigned long *)p)
		:"r" (val)
		: "cc","memory"
	);
	tmp1=tmp;
}

int main(int argc,char *argv)
{
	unsigned long a=4;
	int b=3;
	my_atomic_add(3,&a);
	printf("%ld\n",a);
	return 0;
}
