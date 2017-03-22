#!/bin/sh
val1=4
val2=5
#result=$(( val1 + val2))
result=`echo "12 * 23.4/12.0+0.6" |bc`
echo $result