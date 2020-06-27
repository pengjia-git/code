#include <iostream>
#include "quote.h"
void bulk_quote::debug()
{
    std::cout<<&min_qty<<"\t"<<&discount<<std::endl;
    std::cout<<&price<<"\t"<<&book_no<<std::endl;
}


double bulk_quote::net_price(std::size_t n)const
{
    if(n>= min_qty)
        return n*(1-discount)*price;
    return n*price;
}


bulk_quote::bulk_quote(const std::string&book,double p,std::size_t n,double disc):
    quote(book,p),min_qty(n),discount(disc)
{
    if((discount > 1) || (discount <0))
        std::cout<<"discount error"<<std::endl;
}