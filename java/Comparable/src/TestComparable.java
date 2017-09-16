
public class TestComparable {

	public static void main(String[] args) {
		Rectangle a1=new Rectangle(7,3);
		CircleFromGenericGeometric a2=new CircleFromGenericGeometric(1.7);
		Rectangle a3=new Rectangle(4,2);
		Rectangle a4=new Rectangle(30,3);
		CircleFromGenericGeometric a5=new CircleFromGenericGeometric(8);
		
		GenericGeometric[] array= {a1,a2,a3,a4,a5};
		java.util.Arrays.sort(array);
//		int i;
//		System.out.println(array.length);
//		for(i=0;i<=array.length;i++);
//			System.out.println(array[i].toString());
		for(GenericGeometric o:array)
			System.out.println(o.toString()+"+++++"+o.getArea());
	}

}
