#include <stdio.h>

struct cache{
	char c;
	char c1;
	int a[7];
	int b;
}__attribute__((packed));
//};


int main()
{
	struct cache a;
	int i;
	printf("%d\n",sizeof(a));
	for(i=0;i<900000000;i++)
		a.b=i;
	return 0;
}
