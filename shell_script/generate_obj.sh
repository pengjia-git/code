#!/bin/bash
obj1="&gui_apk_low_bat_str0_320x240_16bit,"
obj2="GOBJ_APK_LOW_BAT_STR0,"
rm 293_obj.txt 
i=0
#for i in $(seq 0);
#do
	temp_obj=`cat in_file.txt|sed -e "s/str0/str$i/"`
	echo $temp_obj >>temp_file1
#done

#for i in $(seq 0);
#do
	temp_obj=`echo $obj1|sed -e "s/str0/str$i/"`
	echo $temp_obj >>temp_file1
#done
	cat temp_file1 >>293_obj.txt
	line="***************line************"
	echo $line>>293_obj.txt

	cat temp_file1|sed -e 's/320x240/1920x135_tv/'>>293_obj.txt
	echo $line>>293_obj.txt

	cat temp_file1|sed -e 's/320x240/480x960/'>>293_obj.txt
	echo $line>>293_obj.txt
	cat temp_file1|sed -e 's/320x240/960x540_tv/'>>293_obj.txt
	echo $line>>293_obj.txt
#for i in $(seq );
#do
	temp_obj=`echo $obj2|sed -e "s/0/$i/"`
	echo $temp_obj >>293_obj.txt
#done
rm temp_file1
todos 293_obj.txt
cat 293_obj.txt
