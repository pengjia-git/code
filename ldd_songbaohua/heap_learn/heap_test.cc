#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <thread>
#include <unistd.h>

void malloc_some_mem()
{
    for(int i=0;i<1000;i++)
        malloc(1*1024);
}

void thread_process(void *p)
{
    while(1)
        sleep(1);
   
}

void create_thread()
{
    //创建一个线程
    std::thread t(thread_process,NULL,10*1024*1024);
    t.detach();
}

int main() {
    while(1)
    {
        getchar();
        //malloc_some_mem();
        create_thread();
    }
    return 0;
}
