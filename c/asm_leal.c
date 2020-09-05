#include <stdio.h>

int main()
{
    int x=3,y=4;
    /*
    * 下条语句在此环境中编译成汇编的结果。
	leal (%eax,%eax,4),%eax
    */
    asm("leal (%1,%1,4),%0":"=r"(y):"0"(x));
    printf("y=%d\n",y);
    return 0;
}