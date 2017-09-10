import java.util.Scanner;
public class Test {
	public static void main(String[] args) {
		Scanner input= new Scanner(System.in);
		
		double side1,side2,side3;
		System.out.println("Please input the triangle three sides");
		side1=input.nextDouble();
		side2=input.nextDouble();
		side3=input.nextDouble();
		Triangle a=new Triangle(side1,side2,side3);

		String color;
		boolean fill;
		
		System.out.println("Please input the triangle color");
		color=input.next();
		a.setColor(color);
		System.out.println("Is this triangle fill?");
		fill=input.nextBoolean();
		a.setFill(fill);
		
		System.out.println(a.getArea()
				+a.toString()
				+a.getColor()
				+a.isFill());
		input.close();
		
	}

}
