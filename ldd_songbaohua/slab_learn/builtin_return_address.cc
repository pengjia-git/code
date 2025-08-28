#include <stdio.h>

void my_function(void) {
    void *return_address = __builtin_return_address(0);
    printf("Return address: %p\n", return_address);
}


int main()
{
	printf("%p\n",main);
	my_function();
	my_function();
	my_function();
	return 0;
}
