#include <stdio.h>
enum a{
  x1=-1,
  x2,
  x3
};
int main()
{
  enum a b;
  b=x2;
  printf("b=%d\n",b);
  return 0;
}
