
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
		super(color,fill);
		this.radius=radius;
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
	
	public String toString()
	{
		return "circle:"+super.toString()+" radius:"+radius;
	}
}
