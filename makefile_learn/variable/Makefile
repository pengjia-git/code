val2="jia"
tar:foo.o bar.o
	@echo $(val2)
	@echo $<
tar: val="3"
foo.o:foo.c
	echo $(val)
	gcc -c -o  $@ $<

bar.o:bar.c
	echo $(val)
	gcc -c -o  $@ $<
clean:
	rm *.o
