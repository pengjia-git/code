#include <stdio.h>

struct a{
  char a[5];
  int b;
  short  c;
 };

struct b{
  //char *d;
  short int e;
  struct a f;
  char g;
};
void example(char acHello[])
{
  printf("%d",sizeof(acHello));
}
int main()
{
  unsigned char aucArray[2][3]={1,2,3,4};
  int i;
  unsigned char *p=aucArray;
  for(i=0;i<6;i++)
    printf("%d ",*p++);
  printf("\n 1 2  3 4  0 0\n");
  return 0;
}
