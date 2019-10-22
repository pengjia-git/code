void swap(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	int a,b;
	int c;

	a=16;
	b=32;

	swap(&a,&b);

	return (a-b);
}
