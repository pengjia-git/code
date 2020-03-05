#include <stdio.h>

void swap(int* p, int* q)
{
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

int is_big(int* p, int* q)
{
	return (*p > * q) ? 1 : 0;
}

/*
max to min

*/
int quicksort(int array[], int size)
{
	int* l_sentinel, *r_sentinel, * ref;

	if (size < 2)
		return 0;

	ref=l_sentinel = array;
	r_sentinel = array + size - 1;

	while (l_sentinel != r_sentinel) {
		if (!is_big(r_sentinel, ref)) {
			r_sentinel--;
			continue;
		}

		if (is_big(l_sentinel, ref)) {
			l_sentinel++;
			continue;
		}

		swap(l_sentinel, r_sentinel);
	}
	swap(ref,l_sentinel);

	quicksort(array, l_sentinel - array);
	quicksort(r_sentinel + 1, array + size - 1 - r_sentinel);
	return 0;
}

int main()
{
	int array[] = { 6,1,2,7,9,3,4,5,10,8,8,9,12,32,2,12,55};
	int i, array_size;

	array_size = sizeof(array) / sizeof(array[0]);
	quicksort(array, array_size);

	for(i=0;i< array_size;i++)
		printf("%d ",array[i]);
	printf("\n");

	return 0;
}