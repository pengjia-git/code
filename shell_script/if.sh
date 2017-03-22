#!/bin/bash
read -p "input your choice " yesno
if [ $yesno = "yes" ] || [ $yesno = "y" ];then
    echo "ok ,continue"
    exit 0

elif [ "$yesno" = "no" ];then
    echo "oh ,interrupt"
    exit 0
else
    echo "i don't know what your choice is"
fi
