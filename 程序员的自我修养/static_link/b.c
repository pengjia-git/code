#include <stdio.h>
double global_a;

int shared =1;
void swap(int *a,int *b)
{
  printf("sizeof %d\n",sizeof(global_a));
	*a^=*b^=*a^=*b;
}
