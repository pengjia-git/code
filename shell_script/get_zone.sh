#!/bin/bash
path=/home/alvin/amba/temp
fromdos $path/zone_source.txt
fromdos $path/zone_china.txt
cat $path/zone_source.txt > temp_file
cat temp_file|cut -d '"' -f 2 >zone_string
cat -n zone_string

#iconv	-f gbk -t utf-8 -o $path/zone_china.txt $path/zone_china.txt
cat $path/zone_china.txt > temp_file_china
cat temp_file_china|cut -d '"' -f 2 >zone_china_string
cat -n temp_file_china
#cat -n zone_china_string

echo >$path/zone_string.txt
#cat zone_string
for i in `seq 1 71`;
do
	zone1=`sed -n "$i p" zone_china_string`	
	zone2=`sed -n "$i p" zone_string`	
	zone3="msg apk_zone_$i\nlang 0 $zone1\nlang 1 $zone2\nlang 2 $zone2\nlang 3 $zone2\nlang 4 $zone2\nlang 5 $zone2\nlang 6 $zone2\nlang 7 $zone2\nlang 8 $zone2\n"
	echo  $zone3 >>$path/zone_string.txt
done
todos $path/zone_string.txt

