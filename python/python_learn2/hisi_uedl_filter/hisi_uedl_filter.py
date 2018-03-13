from struct import *

def line_process(line):
	ascii_show=[]
	for c in line:
		a=unpack("B",c)		
		if a[0] >= 32 and a[0] <= 126:
			ascii_show.append(c)
	ascii_show.append("\n")
	return ''.join(ascii_show)
		
fd_in=open(r"raw.uedl" ,'rb')
fd_out=open("hisi_log_out.txt",'w')

count=0
for line in fd_in:
	str=line_process(line)
	count+=1
	fd_out.write(str)

print "count=%d"%count
fd_in.close()
fd_out.close()
