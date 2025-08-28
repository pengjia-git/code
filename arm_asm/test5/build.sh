rm a.out
rm test_disasm
gcc -g   test.c
objdump -D -S ./a.out > test_disasm
#objdump -d -S  ./a.out > test_disasm
