#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[55];
    const char *p;
    p=buf;
    memset(buf,0,55);
    buf[1]='0';
    // *p='c';
    return 0;
}