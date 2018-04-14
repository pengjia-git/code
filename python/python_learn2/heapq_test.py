from heapq import *
from random import *

count=0
repeat_count={}
for i in range(1000):
	data=int(uniform(0,1000000))
	if data in repeat_count:
		repeat_count[data]+=1
	else:
		repeat_count[data]=1

for i in repeat_count:
	if repeat_count[i] > 1 :
		count+=1

print count
