
public class DotClass {

	public static void main(String[] args) {
		System.out.println(DotClass.class);
        DotClass m = new DotClass();
        Class mainClass = m.getClass();
        System.out.println(mainClass);
        System.out.println(DotClass.class==mainClass);
	}

}
