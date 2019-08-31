ifneq ($(KERNELRELEASE),)
obj-m:=helloworld.o
else
PWD:=$(shell pwd)
KVER?=$(shell uname -r)
KDIR:=/home/jia/work/code/linux-5.2.9
all:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions *.symvers *.order
endif
