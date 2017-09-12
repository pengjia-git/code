
public class ExceptionTest {

	public static void main(String[] args) {
		CircleFromGenericGeometric c1=new CircleFromGenericGeometric();
		try {
			c1.setRadius(-2.0);
		}
		catch(InvalidRadiusException ex) {
			System.out.println(ex.getRadius());
		}
		finally{
			System.out.println("It will be printed in any case");
		}
		System.out.println(c1.getArea());
	}

}


