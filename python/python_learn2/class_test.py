class Employee(object):
	empCount = 0
	
	def __init__(self,name,salary):
		self.name = name
		self.salary = salary
		Employee.empCount +=1

	def displayCount(self):
		print "Total Employee %d" % Employee.empCount
	
	def displayEmployee(self):
		print "Name:",self.name," Salary:",self.salary


a=Employee("pengjia",17500)	
b=Employee("pengwa",11000)

a.displayCount()
b.displayCount()

a.displayEmployee()
b.displayEmployee()

