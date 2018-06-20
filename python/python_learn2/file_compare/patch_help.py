#coding:utf-8
from filecmp import *
import os
import re
import sys
import shutil

u02_old_path='C:/Users/pengj/Desktop/temp/soft'
work_path='e:/work/iot/RDA/server/8908A/soft'
patch_path='C:/Users/pengj/Desktop/temp/patch/soft'

#存储svn更新的文件---txt被加密了，读到是乱码。
new_files_path='C:/Users/pengj/Desktop/temp/svn1210.sn'


#读取svn更新的文件列表中
def get_new_files(newfile_document):
    files=[]
    fd=open(newfile_document)
    for file in fd:
    	file=file.strip()
    	if os.path.exists(file):
    		file=file.replace("//",'/')
    		index=file.find("soft")
    		file=file[index+len("soft"):]
    		files.append(file)
    fd.close()
    return files
    
    
#获取path 下所有文件
def file_list(path):
	files=[]
	for root, dirs, file_names in os.walk(path): 
		for name in file_names:
			temp= os.path.join(root,name)
			temp=temp.replace("\\",'/')
			index=temp.find("soft")
			temp=temp[(index+len("soft")):]
			#print "----"+temp
			files.append(temp)
	return files


def dispaly_list_as_file(list):
	for file in list:
		print file


def write_result_to_file(file,ture_files,false_files):
	fd=open(file,"w")
	for file in ture_files:
		fd.write(file+"\n")
	fd.write("-"*80+'\n')
	for file in false_files:
		fd.write(file+"\n")
	fd.close()

files=file_list(patch_path)
#files=get_new_files(new_files_path)


def copy_patch_to_work(patch_file,work_file):
	if not (os.path.exists(patch_file) and os.path.exists(work_file)):
		print "copy_patch_to_work --warming"
		return
	shutil.copy(patch_file,work_file)

ture_files=[]
false_files=[]

for file_path in files:
	file1=u02_old_path+file_path
	file2=work_path+file_path
	file3=patch_path+file_path
	if not (os.path.exists(file1) and os.path.exists(file2)):
		false_files.append(file_path)
		print file1
		continue

	if cmp(file1,file2):
		ture_files.append(file_path)
		#print file2
		#print file3
		#print '-'*50
		copy_patch_to_work(file3,file2)
	else:
		false_files.append(file_path)

write_result_to_file("result.txt",ture_files,false_files)
