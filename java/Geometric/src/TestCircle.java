
public class TestCircle {

	public static void main(String[] args) {
		CircleFromGenericGeometric c1=new CircleFromGenericGeometric();
		c1.printCircle();
		
		CircleFromGenericGeometric c2=new CircleFromGenericGeometric(3);
		c2.printCircle();
		System.out.println(c2.getColor());
		System.out.println(c2.getArea());
	}

}
