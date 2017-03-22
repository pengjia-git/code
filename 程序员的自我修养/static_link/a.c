#include <stdio.h>
extern int shared;
int global_a;
int main()
{
  int a =100;
  printf("size=%d\n",global_a);
  swap(&a,&shared);
}
