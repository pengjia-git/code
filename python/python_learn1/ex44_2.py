class Parent(object):
    def override(self):
        print "PARENT OVRIRIDE()"

class Child(Parent):
    def override(self):
        print "CHILD OVERRIDE()"
        super(Child,self).override()

a=Parent()
b=Child()

a.override()
b.override()

