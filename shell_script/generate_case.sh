#!/bin/bash
path=/home/alvin/amba/temp
for obj in `seq 0 11`
do
	echo "case $obj:" >>$path/11.txt
done
todos $path/11.txt

