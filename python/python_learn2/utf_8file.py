#coding=utf-8
import codecs

f=codecs.open("pru_uni.txt",'w',"utf-8")
txt=unicode('抨击几\n','utf-8')
f.write(txt)
f.write(u"中文儿\n")
f.close()
