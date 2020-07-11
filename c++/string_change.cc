#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string a("pengja");
    auto it=a.begin();
    while(it!=a.end()){
        if(*it == 'a'){
            a.insert(it,'i');
            break;
        }
        it++;
    }
    cout<<a<<endl;
    return 0;
}