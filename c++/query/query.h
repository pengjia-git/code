#include <string>
#include <iostream>
#include <vector>

class query{
    public:
        query & analyze(std::istream &in);
        std::size_t size(){return lines.size();}
        void show_db();
        //search dst in src
        bool match(const std::string src,const std::string dst);
        void show_result(const std::vector<int> v);
        virtual std::vector<int> search(const std::string s);
    protected:
        //我想第一个元素是空的，这样行号就是从1开始
        std::vector<std::string> lines={""};
};


class word_query:public query{
    public:
        virtual std::vector<int> search(const std::string s);
};

class not_query:public query{
    public:
        std::vector<int> search(const std::string s);
};

class and_query:public word_query{
    public:
        std::vector<int> search(const std::string s1,const std::string s2);
};

class or_query:public word_query{
    public:
        std::vector<int> search(const std::string s1,const std::string s2);
};