#include <iostream>

class CBenz{
    public:
        void run()
        {
            std::cout << "Benz is running" << std::endl;
        }
};

class CDriver{
    public:
        void drive(CBenz &benz)
        {
            benz.run();
        }
};

int main()
{
    CBenz benz;
    CDriver xiaoming;
    xiaoming.drive(benz);
    return 0;
}