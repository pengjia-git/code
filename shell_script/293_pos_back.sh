#!/bin/bash
files=`find 292_UI_CHN -name "*zb*"`
echo $files
for file in $files;
do
	mv $file 293_pos_bz
done
