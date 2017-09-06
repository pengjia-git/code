

class CircleWithStaticMember {
	double radius;
	static int numberOfObjects=0;
	CircleWithStaticMember()
	{
		radius=0;
		numberOfObjects++;
	}
	CircleWithStaticMember(double newRadius)
	{
		radius=newRadius;
		numberOfObjects++;
	}
	public static int getNumberOfObjects()
	{
		return numberOfObjects;
	}
	
	public double getArea()
	{
		return Math.PI*radius*radius;
	}
}
