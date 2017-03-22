#!/bin/bash
path=/home/alvin/amba/temp
fromdos $path/string.txt
temp=`cat $path/string.txt|grep "msg"|cut -d " " -f 2`
echo $temp
for obj in `echo $temp`
do
	obj=`echo $obj|tr 'a-z' 'A-Z'`
	echo '{'$obj"_L,\c" >>$path/pos_array.txt
	echo $obj"_T,\c" >>$path/pos_array.txt
	echo $obj"_W,\c" >>$path/pos_array.txt
	echo $obj"_H\c" >>$path/pos_array.txt
	echo '},' >>$path/pos_array.txt
done
todos $path/pos_array.txt

