from sys import *
f=open("file_test.txt",'w')

str=stdin.readlines()
for i in str:
	f.write(i)
f.close()
