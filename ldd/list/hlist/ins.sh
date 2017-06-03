#!/bin/bash
#insmod hlist.ko
make clean
make
sudo rmmod hlist
sudo insmod hlist.ko
