#!/bin/bash

cat $1 |grep 'chan0_frames_per_sec=' > temp1
cat temp1 |cut -d= -f 2|awk '{print $1}' > cpu
cat cpu
total_lines=`cat cpu|wc -l`
echo "count=${total_lines}"
cat cpu|awk '{sum=sum+$1+0} END {print "Average = ", sum/NR}'
cat cpu|awk 'BEGIN {max = 0} {if ($1 +0 > max+0 ) max=$1 fi} END {print "Max=", max}'
cat cpu|awk 'BEGIN {min = 1999999} {if ($1+0 <min+0 ) min=$1 fi} END {print "Min=", min}'
rm cpu
rm temp1
