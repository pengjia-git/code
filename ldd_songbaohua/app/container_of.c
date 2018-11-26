#include <stdio.h>

#define offsetof(type,member) (\
		(size_t)&(((type *)0)->member)\
		)
struct test1{
char a;
int b;
float c;
};
int main()
{
	printf("%ld\n",sizeof(struct test1));
	printf("%ld\n",offsetof(struct test1,a));
	printf("%ld\n",offsetof(struct test1,b));
	printf("%ld\n",offsetof(struct test1,c));
	return 0;	
}
