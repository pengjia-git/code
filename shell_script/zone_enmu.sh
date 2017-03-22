#!/bin/bash
path=/home/alvin/amba/temp/
file=zone_enum.txt
rm ${path}${file}
zone_enum="MENU_SETUP_ZONE"
for i in `seq 2 71`;
do
	new_zone_enum="$zone_enum""$i"","
	echo  $new_zone_enum>>${path}${file}
done
todos ${path}${file}

