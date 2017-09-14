
public class TestAbstract {

	public static void main(String[] args) {
		CircleFromGenericGeometric c1=new CircleFromGenericGeometric(1);
		Rectangle r1=new Rectangle(2,3);
		System.out.println(isAreaEqual(c1,r1));
	}

	public static boolean isAreaEqual(GenericGeometric a1,GenericGeometric a2)
	{
		double area1,area2;
		area1=a1.getArea();
		area2=a2.getArea();
		if(Math.abs(area1-area2) < 1)
			return true;
		return false;
	}
}
