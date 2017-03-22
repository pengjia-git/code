#!/bin/bash

files=`find $1`
i=0
for file in $files;
do 

#	echo $file
	
#	file=00181.png
  #  $i++
#	new_filename=`echo ${file}|sed -e "s/\{[0-9][0-9][0-9][0-9][0-9]\.png\}/\1/"`
	new_filename=`echo ${file}|cut -c 23-`
	echo $new_filename
	
    mv $file ../amba/font/$new_filename

done

