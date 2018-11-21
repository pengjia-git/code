kernel_ver=$(shell uname -r)

obj-m +=signal.o	

signal:
	make -C /lib/modules/$(kernel_ver)/build M=$(CURDIR) modules

clean:
	make -C /lib/modules/$(kernel_ver)/build M=$(CURDIR) clean
