#!/bin/bash
#insmod list.ko
make clean
make
sudo rmmod list
sudo insmod list.ko
