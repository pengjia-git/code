#!/bin/bash
#对谈式脚本，从用户输入中读取变量。
read -p "Please input your first name:" firstname
read -p "Please input your last name:" lastname
echo  "\nYour full name is:$firstname $lastname"
