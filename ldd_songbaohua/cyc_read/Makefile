kver=$(shell uname -r)
build_path=/lib/modules/$(kver)/build

obj-m +=cyc_read.o

build:
	make -C $(build_path) M=$(CURDIR) modules
clean:
	make -C $(build_path) M=$(CURDIR) clean
