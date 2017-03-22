#!/bin/bash
fromdos $1
obj=`cat $1`
rm result.txt
for i in $(seq 2 11);
do
	echo $obj |sed -e "s/2/$i/g">>result.txt
done
todos result.txt
