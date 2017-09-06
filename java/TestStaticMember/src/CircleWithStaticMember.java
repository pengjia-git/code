

class CircleWithStaticMember {
	private double radius;
	private static int numberOfObjects=0;
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
	public double getRadius()
	{
		return radius;
	}
	
	public boolean setRadius(double newRadius)
	{
		if(newRadius <0)
			return false;
		radius=newRadius;
		return true;
	}
	
	public double getArea()
	{
		return Math.PI*radius*radius;
	}
	
	public static void PrintCircle(CircleWithStaticMember circle)
	{
//		circle.setRadius(10);
		System.out.printf("circle radius=%f,area=%f\n",
				circle.getRadius(),circle.getArea());
	}
}
