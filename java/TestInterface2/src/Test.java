
public class Test {

	public static void main(String[] args) {
		B a=new B();
		a.m1();
	}

}

interface A{
	public void m1();
}


class B implements A{
	public void m1() {
		System.out.println("m1");
	}
}