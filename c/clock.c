#include <time.h>
#include <stdio.h>


/*
when input equal 1000,

1656817675 835218883
1656817675 835231825
diff=12942

when input equal 100
1656817634 246859615
1656817634 246861151
diff=1536
jia@jia-KLV-WX9:~/code/c$ ./a.out 
1656817635 128513558
1656817635 128515221
diff=1663
*/
int sum(int a)
{
    int i;
    int res=0;
    for (i=0;i<a;i++)
        res+=i*2;
    return res;
}
int main()
{
    int ret;
    struct timespec time;
    struct timespec before,after;
    ret=clock_getres(CLOCK_REALTIME,&time);
    if(ret )
        return -1;
    // printf("%ld %ld\n",time.tv_sec,time.tv_nsec);
    clock_gettime(CLOCK_REALTIME,&before);
    ret=sum(1000);
    //printf("ret=%d\n",ret);
    clock_gettime(CLOCK_REALTIME,&after);
    printf("%ld %ld\n",before.tv_sec,before.tv_nsec);
    printf("%ld %ld\n",after.tv_sec,after.tv_nsec);
    printf("diff=%ld\n",after.tv_nsec-before.tv_nsec);

    return 0;
}