#include <iostream>
#include <vector>
#include <set>
#include "query.h"
query & query::analyze(std::istream &in)
{
    std::string line;
    while(getline(in,line))
        lines.push_back(line);
    return *this;
}


void query::show_db()
{
    if(lines.size()<= 1)
        return;
    for(std::string a:lines)
        std::cout<<a<<std::endl;
}

void query::show_result(const std::vector<int> v)
{
    int i;
    for(i=0;i<v.size();i++)
        std::cout<<v[i]<<" "<<lines[v[i]]<<std::endl;
}

bool query::match(const std::string src,const std::string dst)
{
    if(std::string::npos != src.find(dst))
        return true;
    return false;
}

std::vector<int> query::search(const std::string s)
{
    std::vector<int> a;
    return a;
}

std::vector<int> word_query::search(const std::string s)
{
    int i;
    std::vector<int> line_num;

    for(i=0;i<lines.size();i++){
        if(match(lines[i],s))
            line_num.push_back(i);
    }
    return line_num;
}

std::vector<int> not_query::search(const std::string s)
{
    int i;
    std::vector<int> line_num;

    for(i=0;i<lines.size();i++){
        if(match(lines[i],s)== false)
            line_num.push_back(i);
    }
    return line_num;
}


std::vector<int> and_query::search(const std::string s1,const std::string s2)
{
    std::vector<int> line_num;
    std::vector<int> line_num1;
    std::vector<int> line_num2;

    line_num1=word_query::search(s1);
    line_num2=word_query::search(s2);
    for(int i:line_num1){
        for(int j:line_num2){
            if(i==j)
                line_num.push_back(i);
        }
    }
    return line_num;
}

std::vector<int> or_query::search(const std::string s1,const std::string s2)
{
    std::set<int> a;
    std::vector<int> line_num1;
    std::vector<int> line_num2;

    line_num1=word_query::search(s1);
    line_num2=word_query::search(s2);
    for(int i:line_num1){
        a.insert(i);
    }


    for(int i:line_num2){
        a.insert(i);
    }

    std::vector<int> line_num;
    for(int i:a)
        line_num.push_back(i);

    return line_num;
}