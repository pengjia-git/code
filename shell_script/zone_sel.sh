#!/bin/bash
path=/home/alvin/amba/temp/
file=zone_sel.txt
rm ${path}${file}
id_base="MENU_SETUP_ZONE"
flag="MENU_SEL_FLAGS_ENABLE"
str_base="STR_APK_ZONE_"
for i in `seq 1 71`;
do
	new_zone_enum="{""$id_base""$i ,""$flag ,\n""$str_base""$i"",0,0,""$id_base""$i"" ,NULL},\n"
	echo  $new_zone_enum>>${path}${file}
done
todos ${path}${file}

