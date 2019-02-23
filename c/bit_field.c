#include <stdio.h>
#pragma messages("bit field is compiling!")
#pragma pack(1)
struct bit_field{
    unsigned age:3;
    unsigned is_femal:1;
    int a;
    char    salary;
};
#pragma pop()
int main()
{
    printf("sizeof=%lu\n",sizeof(struct bit_field));
    return 0;
}