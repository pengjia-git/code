#!/bin/bash
read -p "input a name" filename
test ! -e $filename &&echo "$filename not exist" && exit 1
test -f $filename && echo "$filename is regular file"
test -d $filename && echo "$filename is a directory"

