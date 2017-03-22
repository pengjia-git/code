#!/bin/bash
path=/home/alvin/amba/temp
fromdos $path/pos.txt
obj=`cat $path/pos.txt`
obj=`echo $obj|tr 'a-z' 'A-Z'`
echo "#define "$obj"_L" >$path/pos.txt
echo "#define "$obj"_T" >>$path/pos.txt
echo "#define "$obj"_W" >>$path/pos.txt
echo "#define "$obj"_H" >>$path/pos.txt

echo $obj"_L," >>$path/pos.txt
echo $obj"_T,\c" >>$path/pos.txt
echo $obj"_W,\c" >>$path/pos.txt
echo $obj"_H\c" >>$path/pos.txt

todos $path/pos.txt

