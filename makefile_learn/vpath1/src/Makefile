CC=g++
INC=../include
CFLAGS=-I $(INC)

main: hello.o main.o
	$(CC) -o $@ hello.o main.o
main.o:main.cpp
	$(CC) $(CFLAGS) -c $<
hello.o:hello.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	-rm main *.o *~
