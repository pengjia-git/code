#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
[][][][][][][]
head    tail

head 与tail相差1个即是满
*/

struct queue {
	int size;
	int head;
	int tail;
	int * buf;
};

struct queue* queue_init(int size)
{
	struct queue* p;

	p = (struct queue*)malloc(sizeof(struct queue)+size*sizeof(int));
	if (p == NULL)
		return NULL;
	p->size = size;
	p->head = p->tail = 0;
	p->buf = (int*)(p + 1);

	return p;
}

int is_empty(struct queue* p)
{
	return p->head == p->tail;
}

int is_full(struct queue* p)
{
	return	((p->tail + 1) % p->size) == p->head;
}

int enqueue(struct queue *p,int e)
{
	if (is_full(p))
		return -1;
	p->buf[p->tail] = e;
	p->tail++;
	if (p->tail == p->size)
		p->tail = 0;
	return 0;
}

int dequeue(struct queue *p,int * e)
{
	if (is_empty(p))
		return -1;
	*e=p->buf[p->head];
	p->head++;
	if (p->head== p->size)
		p->head= 0;
	return 0;
}
int main()
{
	struct queue* p;
	struct queue* q;
	int a;
	int ret;

	p = queue_init(10);
	q = queue_init(10);
	if (p == NULL || q==NULL) {
		printf("malloc fail\n");
		return -1;
	}

	enqueue(p,6);
	enqueue(p,3);
	enqueue(p,1);
	enqueue(p,7);
	enqueue(p,5);
	enqueue(p,8);
	enqueue(p,9);
	enqueue(p,2);
	enqueue(p,4);

	while (!is_empty(p)) {
		ret=dequeue(p,&a);
		if (ret)
			break;
		ret=enqueue(q,a);
		if (ret)
			break;

		ret=dequeue(p,&a);
		if (ret)
			break;

		ret=enqueue(p,a);
		if (ret)
			break;

	}

	while (!is_empty(q)) {

		ret=dequeue(q,&a);
		if (ret)
			break;

		printf("%d ",a);
	}
	printf("\n");
	return 0;
}