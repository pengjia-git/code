   as test.S -o test.o
   ld test.o -o test -Map test.map -lc
   objdump -D -S test > test_disasm
