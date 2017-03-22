#!/bin/bash
infile=../temp1/warningsystem.txt
fromdos $infile 

	cp $infile temp_file1
	cat temp_file1 >293_obj.txt
	line="***************line************"
	echo $line>>293_obj.txt

	cat temp_file1|sed -e 's/320x240/1920x135_tv/'>>293_obj.txt
	echo $line>>293_obj.txt

	cat temp_file1|sed -e 's/320x240/480x960/'>>293_obj.txt
	echo $line>>293_obj.txt
	cat temp_file1|sed -e 's/320x240/960x540_tv/'>>293_obj.txt
	echo $line>>293_obj.txt

rm temp_file1
todos  293_obj.txt
