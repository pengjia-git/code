#coding:utf-8
from filecmp import *
import os
import re

u02_path='E:/document/rda/rda_original/u02/soft'
u02_old_path='E:/document/rda/rda_original/u02_old/soft'
work_path='e:/work/iot/RDA/8908A/soft/'
patch_path='C:/Users/pengj/Desktop/patch'

def file_list(path):
	files=[]
	for root, dirs, file_names in os.walk(path): 
		for name in file_names:
			temp= os.path.join(root,name)
			#temp=re.escape(temp)
			#re.sub('\\','/',temp)
			temp=temp.replace("\\",'/')
			#print "1:",temp
			index=temp.find("patch")
			temp=temp[(index+len("patch")):]
			files.append(temp)
			#print "2:",temp
	return files

files=file_list(patch_path)

def dispaly_list_as_line(list):
	for file in list:
		print file

ture_files=[]
false_files=[]
for file_path in files:

	#file_path='/target/include/tgt_dsm_cfg.h'
	#print type(file_path)
	file1=u02_old_path+file_path
	file2=work_path+file_path
	if not (os.path.exists(file1) and os.path.exists(file1)):
		#print file_path,"false"
		false_files.append(file_path)
		continue

	if cmp(file1,file2):
		ture_files.append(file_path)
	else:
		false_files.append(file_path)

dispaly_list_as_line(ture_files)
print "-"*80
dispaly_list_as_line(false_files)