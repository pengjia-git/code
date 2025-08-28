/*
jia@jia-KLV-WX9:~/code/c/weak$ gcc weak.c sum.c
jia@jia-KLV-WX9:~/code/c/weak$ ./a.out 
i am sum 2
4
jia@jia-KLV-WX9:~/code/c/weak$ gcc weak.c 
jia@jia-KLV-WX9:~/code/c/weak$ ./a.out 
i am sum 1
3
*/
#include <stdio.h>
extern int sum(int a,int b);

int __attribute__((weak)) sum(int a,int b)
{
    printf("i am sum 1\n");
    return a+b;
}

int main()
{
    int a=1,b=2;
    printf("%d\n",sum(a,b));
    return 0;
}
