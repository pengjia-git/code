def add(a,b):
    return a+b

def subtract(a,b):
    return a-b

def multiply(a,b):
    return a*b

def divede(a,b):
    return a/b


age = subtract(2016,1988)
height =add(0,170)
weight =multiply(66.2,2)
iq= divede(240,2)

print "age: %d ,Height: %d ,Weight: %f ,IQ: %d"%(age,height,weight,iq)

what=add(age,subtract(height,multiply(weight,divede(iq,2))))
print "what=%d"%what
