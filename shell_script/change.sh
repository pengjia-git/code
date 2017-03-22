#!/bin/bash
fromdos in.txt
rm -rf temp1
rm -rf temp2.txt
sed -f in.sed in.txt >temp1
cat temp1>>temp2.txt
cat temp1|sed -e "s/320x240_16bit/960x540_tv_16bit/" >>temp2.txt
cat temp1|sed -e "s/320x240_16bit/1920x135_tv_16bit/" >>temp2.txt
cat temp1|sed -e "s/320x240_16bit/480x960_16bit/" >>temp2.txt
rm temp1
todos temp2.txt
