#include <string>
#include "sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    sales_data a;
    cout<<a.units_sold<<endl;
    read(cin,a);
    print(cout,a);
    return 0;
}

double sales_data::avg_price()
{
    if(units_sold == 0)
        return 0;
     return revenue/units_sold;
}


sales_data & sales_data::combile(sales_data & a)
{
    units_sold+=a.units_sold;
    revenue+=a.revenue;
    return *this;
}


std::istream &read(std::istream& in,sales_data & a)
{
   return in>>a.book_no>>a.units_sold>>a.revenue;
}

std::ostream &print(std::ostream& out,sales_data & a)
{
   return out<<a.book_no<<"\t"<<a.units_sold<<"\t"<<a.revenue;
}