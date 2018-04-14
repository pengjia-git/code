import os
from os.path import join, getsize
for root, dirs, files in os.walk('/Users/jia/python'):
	print "1root ",root
	print "dirs ",dirs
	print "files ", files	
