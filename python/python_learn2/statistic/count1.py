from re import *
import sys


fd=open("history.txt")

pat="[ ]+"
s=compile(pat)

dict={}
line_sum=0
for line in fd:
	line_sum+=1
	line=line.strip("\n")
	words=s.split(line)
	#print words
	cmd=words[2]
	if cmd in dict:
		dict[cmd]+=1
	else:
		dict[cmd]=1

cmd_list=[]

for key in dict:
	cmd_list.append((key,dict[key]))

#print cmd_list
def get_count(cmd_tuple):
	return cmd_tuple[1]

cmd_list.sort(key=get_count,reverse=True)


sum=0
for cmd_t in cmd_list:
	sum+=cmd_t[1]
	print cmd_t[0],cmd_t[1]

print sum,line_sum
