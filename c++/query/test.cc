#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include "query.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc,char*argv[])
{
    or_query a;
    query &b=a;
    a.analyze(cin);
    std::vector<int> line=b.search("code");
    cout<<line.size()<<endl;
    a.show_result(line);
    return 0;
}