#include <stdio.h>

struct in_1{
	int a;
	int b;
};

struct out{
	struct in_1 z;
};

struct int_size{
	int c;
};

/*struct 只是包裹了变量，占用空间的只有变量，struct 只是语法上有含义，并不占用任何
空间。*/
int main()
{
	struct out a;
	printf("size of in_1 =%d\n",sizeof(struct in_1));
	printf("size of out =%d\n",sizeof(struct out));
	printf("size of in_1 in out=%d\n",sizeof(a.z));
	printf("size of int=%d\n",sizeof(int));
	printf("size of int_size=%d\n",sizeof(struct int_size));
	return 0;
}

