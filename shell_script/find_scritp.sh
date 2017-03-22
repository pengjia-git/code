#!/bin/bash

files=`find $1 -name "*.sh"`
for file in $files;
do 
	cp $files shell_script/
done

