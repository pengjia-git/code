#include <iostream>
#include "quote.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    bulk_quote a("123",108,10,0.1);
    quote b("456",100);
    quote *p=&b;
    cout<<p->net_price(1)<<endl;
    cout<<p->net_price(8)<<endl;
    cout<<p->net_price(10)<<endl;
    a=b;
    cout<<b.isbn()<<endl;
    return 0;
}