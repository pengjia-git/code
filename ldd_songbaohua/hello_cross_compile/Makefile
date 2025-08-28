CROSS_COMPILE=arm-linux-gnueabihf-
KDIR=/home/jia/work/linux-5.18.5
CC:=$(CROSS_COMPILE)gcc
LD:=$(CROSS_COMPILE)ld

# Kernel modules
obj-m += hello.o

# Specify flags for the module compilation.
#EXTRA_CFLAGS=-g -O0

build: kernel_modules

kernel_modules:
	make -C $(KDIR) M=$(CURDIR) modules ARCH=arm
	sudo mount -o loop /home/jia/work/busybox-1.35.0/rootfs.ext4 /mnt/
	sudo cp hello.ko /mnt/usr
	sudo chmod +x /mnt/usr/hello.ko
	sudo umount /mnt
clean:
	make -C $(KDIR) M=$(CURDIR) clean
