#include <iostream>
#include <chrono>
#include <malloc.h>

const int kNumIterations = 5000000;

struct AlignedData {
    int data[15];
    int flag;
};

//test1 
void test1()
{
    for(int i=0;i<kNumIterations;i++)
    {
        AlignedData *p=new AlignedData;
        p->flag=3;
        delete p;
    }
}


void test2()
{
    //struct AlignedData cache_array[10];
    int num=10;
   void *cache_array=malloc(sizeof(int)*num+sizeof( AlignedData)*num); 
   int *index=(int *)cache_array;
   AlignedData *objects=(AlignedData *)((int *)cache_array+num);
   for(int i=0;i<num;i++)
    index[i]=1;//1表示改索引指向的对象是空闲状态。

    for(int i=0;i<kNumIterations;i++)
    {
       AlignedData *p;
       int tmp_index;
      for(int j=0;j<num;j++)  
        if(index[j]==1)
        {
            tmp_index=j;
            break;
        }

      p= objects+tmp_index;
      p->flag=3;
      index[tmp_index]=0;

    }
    free(cache_array);
}

int main() {

    // 测量对齐的内存访问时间
    auto start = std::chrono::high_resolution_clock::now();
    test1();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> alignedDuration = end - start;

    // 测量不对齐的内存访问时间
    start = std::chrono::high_resolution_clock::now();
    test2();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> unalignedDuration = end - start;

    std::cout << "test1:" << alignedDuration.count() << " 秒" << std::endl;
    std::cout << "test2:" << unalignedDuration.count() << " 秒" << std::endl;

    return 0;
}
