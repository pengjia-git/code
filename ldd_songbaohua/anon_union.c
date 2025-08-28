#include <stdio.h>

struct Example {
    int type;  // 表示当前使用的数据类型
    union {
        int intValue;
        float floatValue;
        char stringValue[20];
    };
};

int main() {
    struct Example ex1;
    ex1.type = 1;
    ex1.intValue = 42;

    struct Example ex2;
    ex2.type = 2;
    ex2.floatValue = 3.14;

    printf("ex1: type=%d, value=%d\n", ex1.type, ex1.intValue);
    printf("ex2: type=%d, value=%.2f\n", ex2.type, ex2.floatValue);

    return 0;
}

