#!/bin/bash
rm temp_pos.txt
rm temp_pos1
obj1=apk_misc_poweroff_str0
obj2=apk_fm_update_str0
obj3=apk_low_bat_str0
for i in $(seq 0 2);
do
	echo $obj1 |sed -e "s/0/$i/">>temp_pos1
done
for i in $(seq 0 3);
do
	echo $obj2 |sed -e "s/0/$i/">>temp_pos1
done
i=0
	echo $obj2 |sed -e "s/0/$i/">>temp_pos1
#cat temp_pos1
cat temp_pos1|tr 'a-z' 'A-Z'>>temp_pos.txt
sed -i -f generate_setting_pos_sed temp_pos.txt
todos temp_pos.txt

