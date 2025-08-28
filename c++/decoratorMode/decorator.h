#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include "beverage.h"
#include <string>

class CCondimentDecorator:public CBeverage{
    
};

class CMilk:public CCondimentDecorator{
    public:
        CMilk(CBeverage & be):mBeverage(be){}
        std::string getDescription(){return "milkWith"+mBeverage.getDescription();}
        float cost(){return 0.1+mBeverage.cost();}
    private:
        CBeverage &mBeverage;
};

class CMocha:public CCondimentDecorator{
    public:
        CMocha(CBeverage & be):mBeverage(be){}
        std::string getDescription(){return "MochaWith"+mBeverage.getDescription();}
        float cost(){return 0.2+mBeverage.cost();}
    private:
        CBeverage &mBeverage;
};
#endif
