#include <stdio.h>
#include <string.h>


int main(int argc,char *argv[])
{
  int d;
  while(1)
    {
      scanf("%d",&d);
      printf("d=%d:ffs=%d\n",d,ffs(d));
    }
  return 0;
}
