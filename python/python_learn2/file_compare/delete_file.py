#coding:utf-8
from filecmp import *
import os
import re
import sys
import shutil
import re
import stat

#work_path='W:/rda/8908A/'
work_path='e:/work/iot/RDA/8908A/'
#存储svn更新的文件---txt被加密了，读到是乱码。
svn_info_path='e:/code/python/python_learn2/file_compare/patch_info.sn'

files=[]
def patch_delete_file_name_from_line(line):
    count=0
    if re.search("Deleted",line):
        return  line.split()[0]
	return

def get_deleted_file_name(file):
    fd=open(file)
    for line in fd :
        line=line.strip()
        name=patch_delete_file_name_from_line(line)
        if name :
            files.append(name)
    fd.close()
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

get_deleted_file_name(svn_info_path)
delete_file()