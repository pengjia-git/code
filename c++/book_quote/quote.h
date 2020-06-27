#include <string>

class bulk_quote;
class quote{
    friend class bulk_quote;
    public:
    quote() =default;
    quote(const std::string &book,double sales_price):
        book_no(book),price(sales_price){}
    std::string isbn() const{return book_no;}
    virtual double net_price(std::size_t n)const
    {return n*price;}
    virtual ~quote()=default;
    
    private:
        std::string book_no;
    protected:
        double price;
};

class bulk_quote:public quote{
    public:
        bulk_quote()=default;
        bulk_quote(const std::string&,double,std::size_t,double);
        double net_price(std::size_t n)const override;
        void debug();
        ~bulk_quote()=default;
    private:
        std::size_t min_qty=0;
        double discount=0.0;
};