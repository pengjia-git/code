/*
 * SimpleSection.c
 *
 * Linux:
 *  gcc -c simplesection.c
 * 
 * Windows:
 * cl simplesection.c /c /Za
*/

int printf(const char * format,...);
__attribute__((section("pengjia12"))) int global=43;
int global_init_var =84;
int global_uninit_var;

void func1(int i)
{
  printf("%d\n",i);
}

int main(void)
{
  static int static_var=85;
  static int static_var2;
   static int x1=0;
  // static int x2=3;
  int a=1;
  int b;

  func1(static_var +static_var2+a+b);

  return a;
}
