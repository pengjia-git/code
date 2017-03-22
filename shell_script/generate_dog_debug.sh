#!/bin/bash
path=/home/alvin/amba/temp
fromdos $path/1.txt
ori_file=$path/1.txt
tar_file=$path/tar.txt
key_temp=`cat $ori_file|cut -d ';' -f 1`
#key_temp=`cat $ori_file| sed -e "s/*U[ 0-9 ]*\(.*\);/\1/"`
#echo $key_temp
echo "#ifdef ENABLE_APK_E_DOG_TEST" > $tar_file 
for key in `echo $key_temp`
do
	pri="p_dog->gps_test.$key"
	echo "app_dog_printf(\"$pri=%d\",$pri);" >> $tar_file
done
echo "#endif" >> $tar_file 
