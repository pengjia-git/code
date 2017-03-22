#!/bin/bash
path=/home/alvin/amba/temp
fromdos $path/string.txt
fromdos $path/show_string.txt
temp=`cat $path/string.txt|grep "msg"|cut -d " " -f 2`
show_str=`cat $path/show_string.txt`
echo $temp
echo "" > $path/pos.txt
#for obj in `echo $temp`
#do
#	echo $obj
#	obj=`echo $obj|tr 'a-z' 'A-Z'`
#	echo "#define "$obj"_L" >>$path/pos.txt
#	echo "#define "$obj"_T" >>$path/pos.txt
#	echo "#define "$obj"_W" >>$path/pos.txt
#	echo "#define "$obj"_H" >>$path/pos.txt
#	echo "" >>$path/pos.txt
#done
i=0
for obj in `echo $temp`
do
	i=$(($i+1))
	temp_show_str=`echo $show_str|sed -e "s/STR0/STR$i/"`
	echo $temp_show_str",\c" >>$path/pos.txt
	obj=`echo $obj|tr 'a-z' 'A-Z'`
	echo "STR_"$obj"," >>$path/pos.txt
	echo $obj"_L,\c" >>$path/pos.txt
	echo $obj"_T,\c" >>$path/pos.txt
	echo $obj"_W,\c" >>$path/pos.txt
	echo $obj"_H\c" >>$path/pos.txt
	echo ');' >>$path/pos.txt
	echo "" >>$path/pos.txt
done
todos $path/pos.txt

