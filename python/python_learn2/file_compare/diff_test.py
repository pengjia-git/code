from difflib import *
s1 = ['bacon\n','egg\n','ham\n']
s2 = ['bacon\n','eggy\n','hamster\n']

for line in unified_diff(s1,s2):
	print line