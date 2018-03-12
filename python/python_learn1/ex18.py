def print_two(*args):
    arg1,arg2=args
    print "arg1:%r,arg2:%r" %(arg1,arg2)

def print_two_again(arg1,arg2):
    print "arg1:%r,arg2:%r"%(arg1,arg2)

def    print_one   (arg1 ) :
    print "arg1:%r"%arg1

def print_none():
    print "I got nothin."

def add(arg1,arg2):
    print "sum=%d"%int(arg1)+int(arg2)
print_two("peng",1)
print_two_again("peng",1)
print_one("First!")
print_none()
#add(1,2)
