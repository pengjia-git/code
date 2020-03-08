struct stack {
	int size;
	int head;
	int *buf;
};

struct stack* stack_init(int size);
int enstack(struct stack* p, int a);
int destack(struct stack* p, int *a);
