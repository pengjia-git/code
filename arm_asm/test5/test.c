#include <stdio.h>

int g_a;
int main(int argc,char *argv[])
{
	int a;
	int *p=&g_a;
	if(a %2 )
		printf("pengjia1\n");
	else
		printf("pengjia2\n");

	switch(a)
	{
		case 1:
			printf("case1\n");
			break;
		case 2:
			printf("case2\n");
			break;
		case 3:
			printf("case3\n");
			break;
		default:
			break;
	}
	return 0;
}



