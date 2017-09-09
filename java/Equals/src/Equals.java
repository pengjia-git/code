
public class Equals {

	public static void main(String[] args) {
//		String a="Welcom";
//		String b=new String("Welcom");
		A a=new A();
		A b=new A();
		B c=new B();
		System.out.println(a==b);
		System.out.println(a.equals(c));	
	}

}
class B extends A{
	
}

class A{
	int a;
	public boolean equals(Object object) {
		if(object instanceof A)
			return a==((A)object).a;
		else
			return this==object;
	}
}