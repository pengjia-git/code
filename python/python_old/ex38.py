states = {
    'Oregon':'OR',
    'Florida':'FL',
    'California':'CA',
    'NEW YORK':'NY',
    'Michigan':'MI'
}

cities = {
    'CA':'San Francisco',
    'MI':'Detroit',
    'FL':'Jacksonville'
}

cities['NY'] = 'New York'
cities['OR'] = 'Portland'

print '-'*10
print "NY State has: ",cities['NY']
print "OR State has: ",cities['OR']


#print some states

print '-'*10
print "Michigan's abbreviation is:",states['Michigan']
print "Florida's abbreviation is:: ",states['Florida'] 

#do it by using the state then cities dict

print '-'*10
print "Michigan has: ",cities[states['Michigan']]
print "Florida has: ",cities[states['Florida']]

print '-'*10
for abbrev ,city in cities.items():
    print "%s has the city %s" % (abbrev,city)

state = states.get('Texas',None)

if not state:
    print "No Texas."


city = cities.get('TX','Does Not Exit')
print "The city for the state 'TX' is : %s" %city
