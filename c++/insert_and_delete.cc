#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void print_v(vector<int> & v)
{
    for(auto a:v)
        cout<<a<<endl;
}

int main()
{
    vector<int> vi{0,1,2,3,4,5,6,7,8,9};
    // vector<int> vi{0,1};

    auto it=vi.begin();
    for(;it!=vi.end();){
        if(*it%2){
            it=vi.insert(it,*it);
            it+=2;
        }
        else{
            it=vi.erase(it);
        }
    }
    print_v(vi);
    return 0;
}
