while True:
	try:
		x=input("Enter first number: ")
		y=input("Enter second number:")
		print x/y
	except :
		print 'invalid value,please retry'
	else:
		break
	finally:
		print "Cleaning up..."
