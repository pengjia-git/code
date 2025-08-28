#include <stdio.h>
#include <string.h>

#define test(z,d,x) {\
char a[100]={0},*b="pengjia";\
(x);\
printf("a=%s b=%s\n",z,d);\
}

int main()
{
    test(a,b,memcpy(a,b,12));
    return 0;
}