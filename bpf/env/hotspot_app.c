#include <stdio.h>
#include <unistd.h>

void busy_work() {
    volatile int sum = 0;
    for (int i = 0; i < 100000000; i++) {
        sum += i;
    }
}

void light_work() {
    volatile int x = 42;
    x += 1;
}

int main() {
    printf("Running hotspot test app...\n");

    for (int i = 0; i < 5; i++) {
        busy_work();
        light_work();
        sleep(1);
    }

    return 0;
}

