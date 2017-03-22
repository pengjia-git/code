#!/bin/sh
rm *.o
rm test test.txt *.a
gcc -c -fno-builtin -nostdlib  entry.c malloc.c stdio.c string.c printf.c
ar -rs minicrt.a malloc.o printf.o stdio.o string.o
gcc -c -ggdb -fno-builtin -nostdlib test.c
ld -static -e mini_crt_entry entry.o test.o minicrt.a -o test
