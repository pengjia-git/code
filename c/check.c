#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd;
    int len, size;
    char str[10];
    char *str1 = "123456\n";
    char *str2 = "7890ab\n";
    len = strlen(str1);

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return -1;

    while (1)
    {
        size = read(fd, str, len);
        if (size != len)
            break;
        if(memcmp(str,str1,len) && memcmp(str,str2,len)){
            printf("%s\n",str);
        }
    }
    close(fd);
    return 0;
}