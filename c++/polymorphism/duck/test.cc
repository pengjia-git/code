#include <iostream>
#include <vector>

#include "duckBase.h"
#include "greenheadDuck.h"
#include "wildDuck.h"
#include "baitDuck.h"

int main()
{
    std::vector<CDuck *> ducks;
    CDuck *p;

    p=new CGreenheadDuck(); 
    ducks.push_back(p);

    p=new CWILDDuck();
    ducks.push_back(p);

    p=new CBaitDuck();
    ducks.push_back(p);

    for(auto & d:ducks)
    {
        d->fly();
        d->display();
    }

    return 0;
}
