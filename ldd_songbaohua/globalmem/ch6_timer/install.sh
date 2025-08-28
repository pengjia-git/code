sudo rmmod globalmem
sudo rm /dev/globalmem
#make clean
make 
sudo insmod globalmem.ko
sudo mknod -m 0666 /dev/globalmem c 230 0
