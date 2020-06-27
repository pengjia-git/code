#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc,char *argv[])
{
    vector<string> a;

    while(true){
        string temp;
        getline(cin,temp);
        if(temp.empty())
            break;
        a.push_back(temp);
    }

    auto begin=a.begin();
    auto end=a.end();
    for(;begin!= end;begin++)
        cout<<*begin<<endl;
    return 0;
}