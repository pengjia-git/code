#include <stdio.h>

int main()
{
	int count=10;
	int fill=3;
	int buf[10];
	int i;

	for (i=0;i<10;i++)
		printf("buf[%d]=%d\n",i,buf[i]);
	asm("cld\n\t"
		"rep\n\t"
		"stosl"
		::"c"(count-1),"a"(fill),"D"((unsigned long)buf)
		:"cx","di");
	for (i=0;i<10;i++)
		printf("buf[%d]=%d\n",i,buf[i]);

	return 0;

}
