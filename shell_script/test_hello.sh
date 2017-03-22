#!/bin/bash
if [ "$#" = "0" ];then
    echo "you must follow a hello param after test_hello.sh"
elif [ ! "$1" = "hello" ];then
    echo "the param must is hello"
else
    echo "hello ,how are you"
fi
