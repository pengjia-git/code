#ifndef __BAITDUCK_H__
#define __BAITDUCK_H__

#include "duckBase.h"

class CBaitDuck:public CDuck{
    public:
        CBaitDuck();
        void display() override;
};
#endif
