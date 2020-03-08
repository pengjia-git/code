#include <stdio.h>
#include "stack.h"

int buttom = 0;

inline int test(int i)
{
	return buttom & (1 << i);
}

inline void reset(int i)
{
	buttom &= ~(1 << i);
}

inline void set(int i)
{
	buttom |= 1 << i;
}

int test_and_set(int i)
{
	int pos;
	int ret;

	pos = 1 << i;
	ret = buttom & pos;
	buttom |= pos;

	return ret;
}

void clean_buttom()
{
	buttom = 0;
}

/*这是三位数，每位上的数不同
如果是6位数呢
*/
int enumerate_test()
{
	int i, j, k;
	int count = 0,a;
	struct stack* p;

	p = stack_init(10);
	if (!p)
		return -1;

	for (i = 1; i <= 9; i++) {
		set(i);
		for (j = 1; j <= 9; j++) {
			if (test_and_set(j))
				continue;
			for (k = 1; k <= 9; k++){
				if (test(k))
					continue;
				printf("%d\n",i*100+j*10+k);
				count++;
			}
			reset(j);
		}
		reset(i);
	}

	printf("count=%d\n",count);
	return 0;

}

int main()
{
	enumerate_test();
	return 0;
}
