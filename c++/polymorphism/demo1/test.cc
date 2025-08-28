#include "virtual.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector<CAnimal*> animals;

    CAnimal *p= new CDog("dog1");
    animals.push_back(p);

    p= new CCat("cat1");
    animals.push_back(p);

    for(auto &aninal:animals)
    {
        std::cout<<aninal->getName()<<std::endl;
        aninal->sound();
    }

    return 0;
}
