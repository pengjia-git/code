#!/bin/bash
rm -rf picked_files
mkdir picked_files

files=`find $1 -name "*.bmp.bmp"`
echo $files
for file in $files;
do 
	mv $file picked_files	
done
#
#files=`find $1 -name "*update*"`
#echo $files
#for file in $files;
#do 
#	cp $file picked_files	
#done
#
#files=`find $1 -name "*low*"`
#echo $files
#for file in $files;
#do 
#	cp $file picked_files	
#done
