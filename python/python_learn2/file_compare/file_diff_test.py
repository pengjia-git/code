#coding:utf-8
from difflib import *
u02_path='E:/document/rda/rda_original/u02/soft'
u02_old_path='E:/document/rda/rda_original/u02_old/soft'
work_path='e:/work/iot/RDA/8908A/soft/'

#patch_path='C:/Users/pengj/Desktop/patch'
file_path='/target/include/tgt_dsm_cfg.h'

d=Differ()
u02_file = ''
with open(u02_path+file_path,'r') as load:
    u02_file = load.readlines()
    load.close()

u02_old_file = ''
with open(u02_old_path+file_path, 'r') as mem:
    u02_old_file = mem.readlines()
    mem.close()

work_file = ''
with open(work_path+file_path, 'r') as mem:
    work_file = mem.readlines()
    mem.close()

diff1=d.compare(u02_file,u02_old_file)
diff2=d.compare(u02_file,work_file)
#print type(diff)
print (''.join(diff))