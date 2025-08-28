#include "book.h"

NovelBook::NovelBook(std::string name, float price)
{
    mName = name;
    mPrice = price;
}

std::string NovelBook::getName()
{
    return mName;
}

float NovelBook::getPrice()
{
    return mPrice;
}



NovelBookOff::NovelBookOff(std::string name,float price):NovelBook(name,price)
{
}

float NovelBookOff::getPrice()
{
    float price=NovelBook::getPrice();
    if( price > 30)
        return price*0.8;
    else
        return price*0.9; 
}
