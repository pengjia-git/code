#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <functional>

using namespace ::std;

vector<function<void(int, int)>> g_vector;

class IInputCB
{
public:
    virtual void operator()(int code, int value) = 0;
};

class FireKey : public virtual IInputCB
{
public:
    FireKey(string firename) { name = firename; }
    void operator()(int code, int value) { cout << "name" << name << " code=" << code << endl; }

private:
    string name;
};

void keyHandCB(int code, int value)
{
    cout << __FUNCTION__ << "code=" << code << "value=" << value << endl;
}

void cb_thread(int n)
{
    while (1)
    {
        cout << __FUNCTION__ << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        for (int i = 0; i < g_vector.size(); i++)
            g_vector[i](12, 3);
    }
}

int main()
{
    thread t(cb_thread, 1);
    g_vector.push_back([](int code, int value) { cout << "lambda code=" << code << "value=" << value << endl; });
    g_vector.push_back(keyHandCB);
    g_vector.push_back(FireKey("Firekey"));
    while (1)
        ;
}