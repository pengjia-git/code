#!/bin/bash

files=`find $1`
rm -rf result_file
mkdir result_file
for file in $files;
do 
	new_filename=`echo $file|grep 'on'`
#	echo $new_filename
	if [ $new_filename ];then
		new_filename=`basename $new_filename`
		cp $1/1.png result_file/on.png
		mv result_file/on.png result_file/$new_filename 
	fi
done

for file in $files;
do 
	new_filename=`echo $file|grep 'off'`
#	echo $new_filename
	if [ $new_filename ];then
		new_filename=`basename $new_filename`
		cp $1/2.png result_file/off.png
		mv result_file/off.png result_file/$new_filename 
	fi
done
