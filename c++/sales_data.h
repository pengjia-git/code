#include <iostream>
#include <string>

struct sales_data{
    std::string isbn() const {return book_no;}
    sales_data & combile(sales_data &);
    double avg_price();

    std::string book_no;
    int units_sold=0;
    double revenue=0;
};
std::istream &read(std::istream&,sales_data &);
std::ostream &print(std::ostream&,sales_data &);