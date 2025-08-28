#ifndef _DUCK_BASE_H_
#define _DUCK_BASE_H_
#include "duckFly.h"

class CDuck{
    public:
        virtual void display() =0;
        void fly();
    public: 
        CFlyBehavior *flyP=nullptr;
};

#endif
