#include <stdio.h>

struct type_a{
	int a;
	float b;
	char c;
};

int main()
{
	int a[100];
	printf("%d\n",sizeof a);
	return 0;
}
