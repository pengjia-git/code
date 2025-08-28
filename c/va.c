#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

struct my_obj{
    char *name;
    struct my_obj *parent;
    int node;
    int ref;
};

void add_obj(struct my_obj *p,char *fmt,...)
{
    char *buf;
    va_list ap;
    va_start(ap,fmt);
    buf=(char*)malloc(256);
    memset(buf,0,256);
    vsnprintf(buf,256,fmt,ap);
    va_end(ap);
    p->name=buf;
}

void test(int a,int b)
{
    int c;
    printf("%p %p %p\n",&a,&b,&c);
}

int main()
{
    struct my_obj a;
    add_obj(&a,"%s-%d","mouse",3);
    printf("name=%s\n",a.name);
    test(1,3);
    return 0;
}