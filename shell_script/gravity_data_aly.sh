#!/bin/bash
fromdos $1
#cp $1 temp_gra_file1
cat $1|grep "x=" >temp_gra_file1 
sed -i "s/x=.*y=.*z=//" temp_gra_file1
#cat temp_gra_file1
#sort -n temp_gra_file1
rm temp_gra_file1
