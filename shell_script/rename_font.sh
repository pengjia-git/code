#!/bin/bash
#new_names=`cat language_unicode.txt`
#old_names=`cat sort_files_name.txt`
#for new_name in $new_names;
#do 
#	echo $new_name
#	mv $new_name 
#done

for i in $(seq 2 63);
do
	new_name=`cat language_unicode.txt|sed -n "$i p" `
	old_name=`cat sort_files_name.txt|sed -n "$i p" `
	echo $old_name
	echo $new_name
	mv  $old_name $new_name
done 
