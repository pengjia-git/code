#include <stdio.h>

struct a{
	char x[0];
}__attribute__((aligned(32)));


struct b{
	char b1[12] ;
	struct a a1;
	char b2[12] ;
};

int main()
{
	printf("size of a=%ld\n",sizeof(struct a));
	printf("size of b=%ld\n",sizeof(struct b));
	return 0;
}


