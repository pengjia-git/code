#kernel_out=/home/jia/work/linux-5.18.5/build_dir
#kernel_out=/home/jia/work/linux-5.18.5
#qemu-system-arm -cpu cortex-a15 -smp 4 -m 4096 -machine type=vexpress-a15 -nographic -serial mon:stdio    -drive if=sd,driver=file,filename=/home/jia/work/busybox-1.35.0/rootfs.ext4 -kernel $kernel_out/arch/arm/boot/zImage  -dtb $kernel_out/arch/arm/boot/dts/vexpress-v2p-ca15-tc1.dtb  -append "console=ttyAMA0 root=/dev/mmcblk0 ro"

qemu-system-arm -M vexpress-a9 -m 128M -kernel /home/jia/work/linux-5.18.5/arch/arm/boot/zImage -dtb /home/jia/work/linux-5.18.5/arch/arm/boot/dts/vexpress-v2p-ca9.dtb -nographic -append "root=/dev/mmcblk0 console=ttyAMA0"   -sd /home/jia/work/busybox-1.35.0/rootfs.ext4
