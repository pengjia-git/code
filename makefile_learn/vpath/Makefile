CC=g++
INC=include
CFLAGS=-I $(INC)
vpath %.cpp src
vpath %.h include

main: hello.o main.o
	$(CC) -o $@ hello.o main.o
main.o:main.cpp hello.h
	$(CC) $(CFLAGS) -c $<
hello.o:hello.cpp hello.h
	$(CC) $(CFLAGS) -c $<

clean:
	-rm main *.o *~
