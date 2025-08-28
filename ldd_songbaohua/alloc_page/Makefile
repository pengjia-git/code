CROSS_COMPILE=/home/jia/work/original_src/L1/tools/linux/toolchain/arm-rockchip830-linux-uclibcgnueabihf/bin/arm-rockchip830-linux-uclibcgnueabihf-
KDIR=/home/jia/work/original_src/L1/sysdrv/source/kernel
CC:=$(CROSS_COMPILE)gcc
LD:=$(CROSS_COMPILE)ld

# Kernel modules
obj-m += hello.o

# Specify flags for the module compilation.
#EXTRA_CFLAGS=-g -O0

build: kernel_modules

kernel_modules:
	make -C $(KDIR) M=$(CURDIR) modules ARCH=arm
clean:
	make -C $(KDIR) M=$(CURDIR) clean
