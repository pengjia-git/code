
public class Triangle 
extends GenericGeometric{
	private double side1,side2,side3;
	
	public Triangle() {
		side1=side2=side3=1.0;
	}
	
	public Triangle(double side1,double side2,double side3) {
		this.side1=side1;
		this.side2=side2;
		this.side3=side3;
	}
	
	public void setSide1(double side) {
		this.side1=side;
	}
	
	public double getSide1() {
		return this.side1;
	}
	
	public void setSide2(double side) {
		this.side2=side;
	}
	
	public double getSide2() {
		return this.side2;
	}
	
	public void setSide3(double side) {
		this.side3=side;
	}
	
	public double getSide3() {
		return this.side3;
	}
	
//	实现方法随便写的
	public double getArea() {
		return side1*side2*side3;
	}
	
	public double getPerimeter() {
		return side1+side2+side3;
	}
	
	public String toString()
	{
		return "Triangle: side1 = "+side1 +
				" side2= "+side2+
				" side3= "+side3;
	}
}
