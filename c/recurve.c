#include <stdio.h>

int facttail(int n, int res)
{
    if (n < 0)
        return 0;
    else if(n == 0)
        return 1;
    else if(n == 1)
        return res;
    else
        return facttail(n - 1, n *res);
}

int fact(int n) {
    if (n < 0)
        return 0;
    else if(n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}



int main()
{
	facttail(1000000,1);
	//fact(1000000);
	return 0;
}