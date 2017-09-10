
public class Final {

	public static void main(String[] args) {
		B a=new B();
		System.out.println(a.toString());
	}

}

final class A{
	
}

//The type B cannot subclass the final class A
class B extends A{
	
}
