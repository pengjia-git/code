#!/bin/bash
path=/home/alvin/amba/temp
gobj=GOBJ_APK_SETTING_BMP
rm $path/GOBJ.txt
for i in `seq 0 9`
do
	echo $gobj$i, >>$path/GOBJ.txt
done
todos $path/GOBJ.txt

