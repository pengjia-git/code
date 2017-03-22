#!/bin/bash
path="/home/alvin/amba/font"
new_name_file=${path}/language_unicode.txt
fromdos $new_name_file
fontfiles=$1
rm -rf $fontfiles/Thumbs.db

new_name=`cat $new_name_file`
#echo $new_name

old_name=`ls  $fontfiles`
#echo $old_name
i=0

for  oldfile in `echo $old_name`;
do
	i=$(($i+1))
#	echo $i $oldfile
	newfile=`echo $new_name|cut -d " " -f $i`
#	echo $i $newfile
	mv $fontfiles/$oldfile $fontfiles/$newfile
#	new_name=`sed -n "$i p"	$path/language_unicode.txt`
#	new_name=`echo $new_name|sed -e"s/bmp.*/bmp/"`
done

