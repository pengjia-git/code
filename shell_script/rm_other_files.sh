#!/bin/bash
files=`find $1 -name "*.bmp"`

echo $1
for file in $files;
do 
	temp=`echo $file|grep -E "004[a A]|005[a A 8 9]"`
	if [ $temp ];then
		echo ""
		echo $file
	else
		rm -f $file
	fi
	#echo $file
done
