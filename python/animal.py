class Animal(object):
    def __init__(self):
        self.animal='jia'
    print "in Animal class"
    pass

class Dog(Animal):
    def __init__(self,name):
        self.name = name

a=Dog("David")

print a.name

