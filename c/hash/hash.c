#include <stdio.h>

#define ARRAY_SIZE(ptr) sizeof(ptr)/sizeof((ptr)[0])

char *test_string[]={
  "pengjia",
  "pengjia1",
  "pengjib",
  "hello"
};

int bkdr_hash(const char *str)
{
  int hash=0;
  const char *p=str;

  while(*p){
    hash=hash*131+*p++;
  }

  return hash;
}

int sdbm_hash(const char *str)
{
  int hash=0;
  const char *p=str;

  while(*p){
    hash=hash*65599+*p++;
  }

  return hash;
}

int rs_hash(const char *str)
{
  int hash=0;
  const char *p=str;
  int magic=63689;
  while(*p){
    hash=hash*magic+*p++;
    magic *=378551;
  }

  return hash;
}

int pjw_hash(const char *str)
{
  static int total_bits=sizeof(int)*8;
  static int threequarters= hash=0;
  const char *p=str;

  while(*p){
    hash=hash*131+*p++;
  }

  return hash;
}


void test(char *p[],int size,int (*fun)(const char *))
{
  int i;

  for(i=0;i<size;i++)
    printf("%d\n",fun(p[i]));
  printf("_____________________________\n");
}

int main()
{

  test(test_string,ARRAY_SIZE(test_string),bkdr_hash);
  test(test_string,ARRAY_SIZE(test_string),sdbm_hash);
  test(test_string,ARRAY_SIZE(test_string),rs_hash);
  return 0;
}
