import struct  
  
#pack - unpack  
print  
print '===== pack - unpack ====='  
  
str = struct.pack("ii", 20, 400)  
print 'str:', str  
print 'len(str):', len(str) # len(str): 8   
  
a1, a2 = struct.unpack("ii", str)  
print "a1:", a1  # a1: 20  
print "a2:", a2  # a2: 400  
  
print 'struct.calcsize:', struct.calcsize("ii") # struct.calcsize: 8  
  
  
#unpack  
print  
print '===== unpack ====='  
  
string = 'test astring'  
format = '5s 4x 3s'  
print struct.unpack(format, string) # ('test ', 'ing')  
  
string = 'he is not very happy'  
format = '2s 1x 2s 5x 4s 1x 5s'  
print struct.unpack(format, string) # ('he', 'is', 'very', 'happy')  
  
  
#pack  
print  
print '===== pack ====='  
  
a = 20  
b = 400  
  
str = struct.pack("ii", a, b)  
print 'length:', len(str) #length: 8  
print str  
print repr(str) # '/x14/x00/x00/x00/x90/x01/x00/x00'  
  
  
#pack_into - unpack_from  
print  
print '===== pack_into - unpack_from ====='  
from ctypes import create_string_buffer  
  
buf = create_string_buffer(12)  
print repr(buf.raw)  
  
struct.pack_into("iii", buf, 0, 1, 2, -1)  
print repr(buf.raw)  
  
print struct.unpack_from("iii", buf, 0)
