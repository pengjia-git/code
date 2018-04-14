import shelve
import math
s=shelve.open("jia")
s['x']="hello world"
s['j']="jia is a world"
s.close()
