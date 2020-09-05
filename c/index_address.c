/*查看buf是怎么汇编的*/
int main()
{
    int i;
    char buf[100];
    for(i=0;i<100;i++)
        buf[i]=3;
    return 0;
}