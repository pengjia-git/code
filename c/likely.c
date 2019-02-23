#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#define unlikely(expr) __builtin_expect (expr, 0)
#define likely(expr)   __builtin_expect (expr, 1)

void test()
{
    int i=0;
    int a,b;

    struct timeval start,end;
    gettimeofday(&start,NULL);
    for(i=0;i<100000;i++){
        //if(unlikely(a<10000))
        //if(likely(a<10000))
        if((a<10000))
            b++;
        a=rand();
    }
    gettimeofday(&end,NULL);
    printf("test2 i=%d time cost=%d b=%d\n",i,end.tv_usec-start.tv_usec,b);

}
int main(int argc, char *argv[]) 
{
    if(likely(1))
    //if(argc)
       argc=3;
    else
        argc=4;
    test();
    return 0;
}
