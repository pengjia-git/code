#!/bin/bash
file=$1
fromdos $1
echo $file
cat $file|cut -c '1-4'|sort|uniq >result_x
cat $file|cut -c '6-9'|sort|uniq >result_y
cat $file|cut -c '11-14'|sort|uniq >result_z


cat $file|cut -c '1-4'>ori_result_x
cat $file|cut -c '6-9'>ori_result_y
cat $file|cut -c '11-14'>ori_result_z
