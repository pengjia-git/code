#include <stdio.h>
#include <stdlib.h>
test(int **pp)
{
  int *p=*pp;
  printf("%x\n",&p);
  p=malloc(1000);
  //*pp=NULL;
  //  *p=NULL;
  printf("*p=%d\n",*p);
}

int main()
{
  int a=13;
  int *p=&a;
  test(&p);
  //  printf("%d\n",*p);
  if(p == NULL)
    printf("test ok\n");
  while(1);
  return 0;
}
