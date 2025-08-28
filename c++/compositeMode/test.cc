#include <string>
#include <iostream>
#include <vector>
#include <memory>

class CFileNode{
    public:
        virtual void display(int depth)=0;
};

class CFile:public CFileNode{
    public:
        CFile(std::string name):mName(std::move(name)){}
        void display(int depth=0)
        {
            std::cout<<std::string(depth*2,' ')<<mName<<std::endl;
        }
    private:
        std::string mName;
};


class CDirectory:public CFileNode{
    public:
        CDirectory(const std::string &name):mName(name){}
        void display(int depth=0)
        {
            std::cout<<std::string(depth*2,' ')<<mName<<std::endl;
            for(auto &it:mChild)
                it->display(depth+1);
        }
        void add(std::shared_ptr<CFileNode> ptr){mChild.push_back(ptr);};
    private:
        std::vector<std::shared_ptr<CFileNode>> mChild;
        std::string mName;
};


int main()
{
    auto file1=std::make_shared<CFile>("file1");
    auto file2=std::make_shared<CFile>("file2");
    auto file3=std::make_shared<CFile>("file3");
    auto dir1=std::make_shared<CDirectory>("dir1withfile12");
    auto dir2=std::make_shared<CDirectory>("dirwithfile3");
    dir1->add(file1);
    dir1->add(file2);
    dir1->add(dir2);
    dir2->add(file3);
    dir1->display(0);
    return 0;
}
