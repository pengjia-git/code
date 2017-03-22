def cheese_and_crakers(cheese_count,boxes_of_crackers):
    print "You have %d cheese." % cheese_count
    print "You have %d boxes of crackers!" % boxes_of_crackers
    print "Man that's enough for a party!"
    print "Get a blanket.\n"

print "We can just give the function numbers directly:"
cheese_and_crakers(20,30)

print "Or,we can use variables from our script:"
amount_of_cheese=10
amount_of_crackers=50

cheese_and_crakers(amount_of_cheese,amount_of_crackers)

print "We can even do math inside too:"
cheese_and_crakers(10+20,5+6)

print "And we can combine the two,variable and math:"
cheese_and_crakers(amount_of_cheese+100,amount_of_crackers+1000)
