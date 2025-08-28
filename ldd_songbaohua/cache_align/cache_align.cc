#include <iostream>
#include <chrono>
#include <malloc.h>

const int kNumIterations = 500000;

struct unAlignedData {
    char pad[63];
    int flag;
}__attribute__((packed));

struct AlignedData {
    char pad[60];
    int flag;
}__attribute__((packed));
//test1 
void test1()
{
    unAlignedData *p=(unAlignedData *)malloc(sizeof(unAlignedData)*kNumIterations);
    for(int i=0;i<kNumIterations;i++)
    {
        p[i].flag=i;
    }
    free(p);
}


void test2()
{
    AlignedData *p=(AlignedData *)malloc(sizeof(AlignedData)*kNumIterations);
    for(int i=0;i<kNumIterations;i++)
    {
        p[i].flag=i;
    }
    free(p);
}

int main() {

    // 测量对齐的内存访问时间
    auto start = std::chrono::high_resolution_clock::now();
    test2();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> alignedDuration = end - start;

    // 测量不对齐的内存访问时间
    start = std::chrono::high_resolution_clock::now();
    test1();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> unalignedDuration = end - start;

    std::cout<<"size of unAlignedData:"<<sizeof(unAlignedData)<<std::endl;
    std::cout<<"size of AlignedData:"<<sizeof(AlignedData)<<std::endl;
    std::cout << "test1:" << alignedDuration.count() << " 秒" << std::endl;
    std::cout << "test2:" << unalignedDuration.count() << " 秒" << std::endl;

    return 0;
}
