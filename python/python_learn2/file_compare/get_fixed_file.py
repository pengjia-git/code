#coding:utf-8
from filecmp import *
import os
import re
import sys
import shutil
import re
import stat

dst_path='W:/rda/8908A/'
src_path='e:/work/iot/RDA/8908A/'
#存储svn更新的文件---txt被加密了，读到是乱码。
svn_info_path='e:/code/python/python_learn2/file_compare/name.sn'

files=[]
def patch_delete_file_name_from_line(line):
    count=0
    if re.search("soft/",line):
        return  line.split()[0]
	return

def get_deleted_file_name(file):
    file_count=0
    fd=open(file)
    for line in fd :
        line=line.strip()
        name=patch_delete_file_name_from_line(line)
        if name :
            files.append(name)
            file_count+=1

    fd.close()
    print file_count
    return files

def delete_file():
    count=0
    for file in files:
        file=work_path+file
        if not os.path.isfile(file):
            print "warming ,no file:",file
            continue
        os.remove(file)
        count+=1
    print count

def copyfile():
    count=0
    for file in l2:
        src_file=src_path+file
        dst_file=dst_path+file
        if not os.path.isfile(src_file)  :
            print "warming ,no file:",file
            continue
        try:
            shutil.copy(src_file,os.path.dirname(dst_file))
        except:
            print "something err"
        count+=1
    print count

get_deleted_file_name(svn_info_path)
l2 = list(set(files))
copyfile()

