#include "duckBase.h"
#include <iostream>

void CDuck::fly()
{
    if(flyP == NULL)
        flyP=new CFlyWithWing(); 
    flyP->fly();
}
