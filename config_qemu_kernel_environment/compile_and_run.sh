cd linux-5.18.5  && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-  -j6 && cd -
#cd linux-5.18.5  && make distclean && make ARCH=arm vexpress_defconfig && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-  -j6 && cd -
sh run_qemu_arm.sh
