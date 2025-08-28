make clean
make 
sudo insmod globalmem.ko
sudo mknod -m 0666 /dev/globalmem0 c 230 0
sudo mknod -m 0666 /dev/globalmem1 c 230 1
sudo mknod -m 0666 /dev/globalmem2 c 230 2

echo "i am globalmem0" > /dev/globalmem0
echo "i am globalmem1" > /dev/globalmem1
echo "i am globalmem2" > /dev/globalmem2

cat /dev/globalmem0
cat /dev/globalmem1
cat /dev/globalmem2