
public class CircleFromGenericGeometric 
	extends GenericGeometric{
	private double radius;
	
	public CircleFromGenericGeometric() {
		radius=0;
	}
	
	public CircleFromGenericGeometric(double radius) {
		this.radius=radius;
	}
	
	public CircleFromGenericGeometric(double radius,
			String color,boolean fill) {
		this.radius=radius;
		setColor(color);
		setFill(fill);
	}
	
	public double getRadius()
	{
		return radius;
	}
	
	public void setRadius(double radius) {
		this.radius=radius;
	}
	
	public double getArea() {
		return Math.PI*radius*radius;
	}
	
	public void printCircle()
	{
		System.out.println("circle:"+toString()+" radius:"+radius);
	}
}
