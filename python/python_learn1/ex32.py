the_count = [1,2,3,4,5]
fruits =['apples','oranges','pears','apricots']
change = [1,'pennies',2,'dimers',3,'quarters']

for number in the_count:
    print "This is count %d" %number

for fruit in fruits:
    print "A fruit of type: %s" %fruit

for i in change:
    print "I got %r" % i

elements = [range(0,9),range(8),range(1,89,3)]

#for i in range(0,6):
 #   print "Adding %d to the list." %i
  #  elements.append(i)

for i in elements:
    for j in i:
        print "Element was: %d" %j
