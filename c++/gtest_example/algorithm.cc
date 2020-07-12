#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
#include <string>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::string;


namespace {

TEST(find_algo,test){
    int val=42;
    vector<int> a={12,3,8,24,42,8};
    auto it=a.cbegin();
    auto res=find(a.cbegin(),a.cend(),42);

    EXPECT_NE(res,a.end());
    EXPECT_EQ(res,it+4);
}

TEST(find_algo,test1){
    int val=43;
    vector<int> a={12,3,8,24,42,8};
    auto res=find(a.cbegin(),a.cend(),val);
    EXPECT_EQ(res,a.end());
}

TEST(count_algo,test){
    int val=42;
    vector<int> a={12,3,8,24,42,8};
    auto it=a.cbegin();
    auto res=count(a.cbegin(),a.cend(),42);

    EXPECT_EQ(res,1);
}

TEST(accumulate_algo,test){
    vector<int> a={1,2,3,4,5,7,19,234,2131};
    auto res=accumulate(a.cbegin(),a.cend(),0);
    int sum=0;
    for(auto it:a)
        sum+=it;
    EXPECT_EQ(res,sum);
}

TEST(equal_algo,test){
    vector<int> a={1,2,3,4,5,7,19,234,2131};
    list<int> b={1,2,3,5};
    bool res=equal(b.cbegin(),b.cend(),a.cbegin());
    EXPECT_FALSE(res);
}
TEST(equal_algo,equal){
    vector<int> a={1,2,3,4,5,7,19,234,2131};
    list<int> b={1,2,3,4,5,7,19,234,2131};
    bool res=equal(b.cbegin(),b.cend(),a.cbegin());
    EXPECT_TRUE(res);
}

TEST(fill_algo,fill){
    vector<int> a={1,2,3,4,5,7,19,234,2131};
    fill(a.begin(),a.end(),12);
    for(auto &b:a)
       EXPECT_EQ(b,12);
}

TEST(sort,sort){
    vector<float> a={7.3,6.3,5,4,3,2,1};

    sort(a.begin(),a.end());
    for(auto b:a)
        cout<<b<<endl;
}

TEST(sort,sort1){
    string a("pengjia");
    sort(a.begin(),a.end());
    cout<<a<<endl;
}


}