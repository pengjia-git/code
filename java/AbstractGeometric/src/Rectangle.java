
public class Rectangle
	extends GenericGeometric{
	private double width;
	private double height;
	
	public Rectangle() {
		width=0;
		height=0;
	}
	
	public Rectangle(double width,double height) {
		this.width=width;
		this.height=height;
	}
	
	public double getArea()
	{
		return width*height;
	}
}
