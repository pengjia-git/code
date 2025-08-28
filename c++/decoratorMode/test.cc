#include <iostream>
#include <unistd.h>
#include "decorator.h"

int main() {
    CHouseBlend hb=CHouseBlend();
    CMilk milk=CMilk(hb);
    CMocha beverage=CMocha(milk);

    std::cout<<beverage.getDescription()<<"cost="<<beverage.cost()<<std::endl;
    return 0;
}
