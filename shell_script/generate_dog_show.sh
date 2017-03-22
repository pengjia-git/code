#!/bin/bash
path=/home/alvin/amba/temp
fromdos $path/dog.txt
ori_file=$path/dog.txt
tar_file=$path/dog_show_result.txt
#key_array=`cat $ori_file|cut -d ';' -f 1`
key_array=`cat $ori_file| sed -e "s/\(APK_.*\),/\1/"`
#echo $key_temp
echo "\n" > $tar_file 
for key in `echo $key_array`
do
	echo "#define ${key}_L" >> $tar_file
	echo "#define ${key}_T" >> $tar_file
	echo "" >> $tar_file
done
echo "\n" >> $tar_file 
cat $tar_file

for key in `echo $key_array`
do
	par1=${key}_L
	par2=${key}_T
	par3_temp=`echo ${key}|tr [A-Z] [a-z] `
	#echo $par3_temp
	par3=${par3_temp}_bid
	
	echo "{ ${par1},${par2},${par3},0x01},//${key}" >> $tar_file
done
echo "\n" >> $tar_file 

for key in `echo $key_array`
do
	par3_temp=`echo ${key}|tr [A-Z] [a-z] `
	#echo $par3_temp
	par3=${par3_temp}_bid
	
	echo "U16 ${par3} []=\n{\n\n};\n" >> $tar_file
done
echo "\n" >> $tar_file 
cat $tar_file
