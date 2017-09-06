
public class TestStaticMember {

	public static void main(String[] args) {
		CircleWithStaticMember circle1=new CircleWithStaticMember();
		System.out.println(CircleWithStaticMember.getNumberOfObjects()); 
		System.out.println(circle1.getArea());
		circle1.setRadius(2);
		System.out.println(circle1.getArea());
		CircleWithStaticMember.PrintCircle(circle1);
	}

}


