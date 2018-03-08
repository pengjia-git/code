def descripePerson(person):
	print "Description of ",person['name']
	print "Age: ",person['age']
	try:
		print 'Occupation:' + person['Occupation']
	except KeyError:
		pass

jia={"name":"pengjia","age":'30',}
descripePerson(jia)