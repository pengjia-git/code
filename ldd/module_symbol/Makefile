ifneq ($(KERNELRELEASE),)
//obj-m:=module_symbol.o
obj-m:=quote_symbol.o
else
PWD:=$(shell pwd)
KVER?=$(shell uname -r)
KDIR:=/lib/modules/$(KVER)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions *.symvers *.order
endif
