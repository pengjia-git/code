#include <stdio.h>

int main()
{
  char a[3]={0};
  a[0]=0x1b;
  a[1]='p';
  printf("%s\n",a);
  return 0;
}
