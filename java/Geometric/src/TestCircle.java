
public class TestCircle {

	public static void main(String[] args) {
		CircleFromGenericGeometric c1=new CircleFromGenericGeometric();
		System.out.println(c1.toString());
		c1.setFill(true);
		CircleFromGenericGeometric.fuck();
		GenericGeometric.fuck();
		CircleFromGenericGeometric c2=new CircleFromGenericGeometric(3,
				"read",true);
		System.out.println(c2.toString());
		System.out.println(c2.getColor());
		System.out.println(c2.getArea());
	}

}
