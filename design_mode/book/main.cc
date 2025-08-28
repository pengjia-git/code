#include "book.h"
#include <vector>
#include <iostream>

int main()
{
   std::vector<NovelBookOff*> store; 
   store.push_back(new NovelBookOff("1",23));
   store.push_back(new NovelBookOff("2",20));
   store.push_back(new NovelBookOff("3",33));

   for(auto it:store)
        std::cout<<it->getName()<<" "<<it->getPrice()<<std::endl;
   return 0;
}