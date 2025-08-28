#include <iostream>
#include "virtual.h"

CAnimal::CAnimal(std::string name):mName(name)
{

}

std::string CAnimal::getName() { return mName; }


void CAnimal::sound() { std::cout << "base animal sound" << std::endl; }


CDog::CDog(std::string name):CAnimal(name){}

void CDog::sound()
{
    std::cout<<"Dog sound"<<std::endl;
}


CCat::CCat(std::string name):CAnimal(name){}

void CCat::sound()
{
    std::cout<<"Cat sound"<<std::endl;
}
