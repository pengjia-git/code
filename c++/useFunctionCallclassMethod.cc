#include <functional>
#include <iostream>
#include <string>

class person
{
public:
    person(std::string name, int age)
    {
        std::cout << "constructor called" << std::endl;
        this->name = name;
        this->age = age;
    }
    ~person()
    {
        std::cout << "destructor called" << std::endl;
    }
    void show(void)
    {
        std::cout << "name: " << name << ", age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};


int test(void)
{
    person a=person("John", 30);
    person b=person("Wilaim", 20);
    using testFunc=  std::function<void(void)>;
    testFunc array[2]={
        std::bind(&person::show, &a),
        std::bind(&person::show,&b)
    };
    for(int i=0;i<2;i++)
        array[i]();
    return 0;
}

int main(void)
{
    std::cout<<"enter test"<<std::endl;
    test();
    std::cout<<"exit test"<<std::endl;
}