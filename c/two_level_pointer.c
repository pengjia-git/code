#include <stdio.h>

int main()
{
    void *buf[3];
    //void **p=&buf[2]; /*方法1*/
    void **p=buf+2; /*方法2*/
    printf("%ld\n",p-buf);
    return 0;
}
