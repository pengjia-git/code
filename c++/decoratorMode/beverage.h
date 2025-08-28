#ifndef _BEVERAGE_H_
#define _BEVERAGE_H_

#include <string>

class CBeverage {
public:
  virtual std::string getDescription() = 0;
  virtual float cost() = 0;
};

class CHouseBlend:public CBeverage{
    public:
        std::string getDescription(){return "houseBlend";}
        float cost(){return 1.20;}
        
};

#endif
