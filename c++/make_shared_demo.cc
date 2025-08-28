#include <iostream>
#include <memory>

class Person
{
public:
    Person(const std::string &name) : name(name)
    {
        std::cout << "Creating person: " << name << std::endl;
    }

    const std::string &getName() const { return name; }
    // 增加析构函数
    ~Person()
    {
        std::cout << "销毁对象" << std::endl;
    }

private:
    std::string name;
};

void test(void)
{
    std::shared_ptr<Person> alice = std::make_shared<Person>("Alice");
}


int main()
{
    test();
    // Create a shared_ptr to a Person object named "Alice"
    std::shared_ptr<Person> alice = std::make_shared<Person>("Alice");

    // Print Alice's name
    std::cout << alice->getName() << std::endl;

    // Create another shared_ptr to the same Person object
    std::shared_ptr<Person> bob = alice;

    // Print Bob's name
    std::cout << bob->getName() << std::endl;

    // Check that alice and bob are referring to the same object
    if (alice == bob)
    {
        std::cout << "alice and bob are referring to the same object" << std::endl;
    }
    else
    {
        std::cout << "alice and bob are referring to different objects" << std::endl;
    }

    return 0;
}
