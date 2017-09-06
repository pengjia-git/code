
public class TestStaticMember {

	public static void main(String[] args) {
		CircleWithStaticMember circle1=new CircleWithStaticMember(1);
		System.out.println(CircleWithStaticMember.getNumberOfObjects()); 
		System.out.println(circle1.getArea());
	}

}


