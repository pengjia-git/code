objects=foo.o bar.o foo.elc
all:$(objects)

$(objects):%.o:%.c
	@gcc -c $< -o $@
.PHONY :clean
clean:
	@rm *.o
