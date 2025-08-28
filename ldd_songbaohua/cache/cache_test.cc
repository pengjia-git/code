#include <iostream>
#include <chrono>
#include <malloc.h>

const int kNumIterations = 1000000;

struct AlignedData {
    int data[15];
} __attribute__((aligned(64)));

struct UnalignedData {
    int data[15];
} __attribute__((packed));

int main() {
    AlignedData* alignedData = static_cast<AlignedData*>(malloc(sizeof(AlignedData)));
    UnalignedData* unalignedData = static_cast<UnalignedData*>(malloc(sizeof(UnalignedData)));

    // 测量对齐的内存访问时间
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < kNumIterations; ++i) {
        int temp = alignedData->data[0];
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> alignedDuration = end - start;

    // 测量不对齐的内存访问时间
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < kNumIterations; ++i) {
        int temp = unalignedData->data[0];
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> unalignedDuration = end - start;

    std::cout << "对齐的内存访问时间: " << alignedDuration.count() << " 秒" << std::endl;
    std::cout << "不对齐的内存访问时间: " << unalignedDuration.count() << " 秒" << std::endl;

    free(alignedData);
    free(unalignedData);

    return 0;
}
