rm a.out
rm test_disasm
gcc -g -O2 test.c
objdump -D -S ./a.out > test_disasm
