#include <iostream>
#include <chrono>
#include <malloc.h>


struct Node {
    int first;
    char c;
    int second;
//}__attribute__((aligned(16)));
}____cacheline_aligned_in_smp;


int main() {
    struct Node a;
    printf("size=%d,%p %p %p\n",sizeof(a),&a.first,&a.c,&a.second);
    printf("align off=%d\n",__alignof__(a));
    return 0;
}
