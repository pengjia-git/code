#include <stdio.h>

/*a>=b return 1*/
int compare(int a, int b)
{
	return (a >= b) ? 1 : 0;
}


void swap(int* p1, int* p2)
{
	int temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

/*from max to min*/
int bubble_sort(int array[],int size)
{
	int i, j=size;

	while (j-- > 0) {
		for (i = 0; i < j; i++) {
			if (!compare(array[i], array[i+1]))
				swap(array+i, array+i+1);
		}
	}
	return 0;
}


int main()
{
	int array[] = {1,3,9,8,7,6,5,4,3,99,103,2,78,9008,12,10,22,17};
	int i;

	bubble_sort(array, sizeof(array)/sizeof(array[0]));

	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		printf("%d\n", array[i]);

		return 0;

}