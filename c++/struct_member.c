#include <stdio.h>

struct type{
    int a;
    int b;
};

struct type * test(struct type *p)
{
    return p;
}
/* struct type * test(struct type *p,int n)
{
    return p;
} */
int main()
{
    struct type a;
    a.a=12;
    a.b=43;
    printf("%d\n",test(&a)->b);
    return 0;
}