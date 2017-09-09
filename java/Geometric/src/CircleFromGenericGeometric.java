
public class CircleFromGenericGeometric 
	extends GenericGeometric{
	private double radius;
	
	public CircleFromGenericGeometric() {
		System.out.println("CircleFromGenericGeometric");
		radius=0;
	}
	
	public CircleFromGenericGeometric(double radius) {
		System.out.println("CircleFromGenericGeometric double");
		this.radius=radius;
	}
	
	public CircleFromGenericGeometric(double radius,
			String color,boolean fill) {
		super(color,fill);
		this.radius=radius;
		//setColor(color);
		//setFill(fill);
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
//		return "circle";
		return "circle:"+super.toString()+" radius:"+radius;
	}
	public static void fuck()
	{
		System.out.println("sb2");
	}
}
