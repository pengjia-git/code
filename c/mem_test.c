#include <stdio.h>
int g_addr=3;
const char *ro_string="what i can do for you";
int main()
{
	char *p;
	int i;

	p=ro_string;

	for(i=0;;i++){
		*p=3;
		printf("i=%d %x\n",i,*p++);
	}
	return 0;
}
