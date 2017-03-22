#!/bin/bash
file=$1
fromdos $file
echo $file
line=`cat $file|grep 'lang '`
#echo $line
for temp in $line
do
	echo $temp
done
