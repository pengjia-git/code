#first install inotify-tools ,used this tool to monitor source files when compile kernel
#sudo apt-get install inotify-tools 
mkdir -p tmp
rm tmp/*
inotifywait -qmre access . > monitor.txt &
make distclean && make ARCH=arm vexpress_defconfig && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-  -j6
sync monitor.txt
pgrep inoti|xargs kill -9
find . -name "*.c" > tmp/all_c_files.txt
#cat monitor.txt |grep "\.c$"|awk '{print $1$3}'|awk '{print substr($1,3)}' > tmp/all_obj_files.txt
cat monitor.txt |grep "\.c$"|awk '{print $1$3}' > tmp/all_obj_files.txt

g++ get_not_compiled_files.cc -o get_not_compiled_files
./get_not_compiled_files
make distclean && make ARCH=arm vexpress_defconfig && make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-  -j6
#rm monitor.txt
#rm -rf tmp
#rm get_not_compiled_files
