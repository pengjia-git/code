#include <stdlib.h>
#include "stack.h"

struct stack* stack_init(int size)
{
	struct stack* p;

	p = (struct stack*)malloc(sizeof(struct stack)+sizeof(int)*size);
	if (p == NULL)
		return p;

	p->size = size;
	p->head = 0;
	p->buf = (int *)(p + 1);

	return p;
}

int enstack(struct stack* p, int a)
{
	if (p->head == p->size)
		return -1;

	p->buf[p->head] = a;
	p->head++;
	return 0;
}

int destack(struct stack* p, int *a)
{
	if (p->head < 0)
		return -1;
	*a = p->buf[p->head];
	p->head--;
	return 0;
}