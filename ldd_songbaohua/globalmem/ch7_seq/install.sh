#!/bin/bash
make 
sudo insmod globalmem.ko
sudo mknod /dev/globalmem c 230 0
sudo chmod /dev/globalmem 666
