#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

using namespace::std;
class Interface;

vector<Interface *> g_vector;

class Interface{
public:
    virtual void onKeyEvent(int code)=0;
};

void cb_thread(int n)
{
    while(1){
        cout<<__FUNCTION__<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        for(int i=0;i<g_vector.size();i++)
            g_vector[i]->onKeyEvent(12);
    //     auto it=g_vector.begin();
    //     while(it!=g_vector.end()){
    //         (*it)onKeyEvent(13);
    //         it++;
    //     }
    }
}


class FireKey:public virtual Interface{
    public:
    FireKey(string firename){name=firename;}
    void onKeyEvent(int code){cout<<"name="<<name<<" code="<<code<<endl;}
    private:
        string name;
};


int main()
{
    thread t(cb_thread,1);
    FireKey key("haixiang");
    FireKey key_hite("hitec");
    g_vector.push_back(&key);
    g_vector.push_back(&key_hite);
    while(1);
}