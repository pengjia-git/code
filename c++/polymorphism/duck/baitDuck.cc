#include "baitDuck.h"
#include "duckFly.h"
#include <iostream>

CBaitDuck::CBaitDuck() { flyP = new CNoFly(); }
void CBaitDuck::display() { std::cout << "bait duck" << std::endl; }
