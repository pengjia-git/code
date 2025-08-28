#include <iostream>

class CCar{
    public:
        virtual void run() = 0;
};

class CTesla:public CCar{
    public:
        void run()
        {
            std::cout << "Tesla is running" << std::endl;
        }
};

class CBenz:public CCar{
    public:
        void run()
        {
            std::cout << "Benz is running" << std::endl;
        }
};

//这个类依赖了Benz类，如果出现Tesla类，那么这个类也需要修改
class CDriver{
    public:
        void drive(CCar & car)
        {
            car.run();
        }
};

int main()
{
    CBenz benz;
    CTesla tesla;
    CDriver xiaoming;
    xiaoming.drive(benz);
    xiaoming.drive(tesla);
    return 0;
}