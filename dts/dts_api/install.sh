mod_name=dts_test
sudo rmmod $mod_name
#sudo rm /dev/globalmem
#make clean
make 
sudo insmod $mod_name.ko
#sudo mknod -m 0666 /dev/globalmem c 230 0
