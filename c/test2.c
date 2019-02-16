#include <stdio.h>
#include <sys/time.h>

#define ARRAY_SIZE (1000*1000)
int array[ARRAY_SIZE];

int test1()
{
    int i=0;
    struct timeval start,end;
    gettimeofday(&start,NULL);
    for(i=0;i<ARRAY_SIZE;i++)
        if(array[i]== 3)
            break;
    gettimeofday(&end,NULL);
    printf("test1 i=%d time cost=%d\n",i,end.tv_usec-start.tv_usec);
    return 0;    
}

int test2()
{
    int i=0;
    struct timeval start,end;
    gettimeofday(&start,NULL);
    array[ARRAY_SIZE]=3;
    for(i=0;;i++)
        if(array[i]== 3)
            break;
    gettimeofday(&end,NULL);
    printf("test2 i=%d time cost=%d\n",i,end.tv_usec-start.tv_usec);
    return 0;    
}
int test3()
{
    int i=0;
    struct timeval start,end;
    gettimeofday(&start,NULL);
    array[ARRAY_SIZE]=3;
    for(i=0;;i+=4){
        if(array[i]== 3)
            break;
        if(array[i+1]== 3)
            break;
        if(array[i+2]== 3)
            break;
        if(array[i+3]== 3)
            break;
    }
    gettimeofday(&end,NULL);
    printf("test3 i=%d time cost=%d\n",i,end.tv_usec-start.tv_usec);
    return 0;    
}
int main()
{
    test1();
    test2();
    test3();
}