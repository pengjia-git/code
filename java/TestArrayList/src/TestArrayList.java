import java.util.ArrayList;
import java.util.Arrays;

public class TestArrayList {

	public static void main(String[] args) {
		ArrayList<String> cityList= new ArrayList<>();
		
		cityList.add("London");
		cityList.add("Denver");
		cityList.add("Paris");
		cityList.add("Miami");
		cityList.add("Seoul");
		cityList.add("Tokyo");
		
		System.out.println("List size="+cityList.size());
		System.out.println("Is Miami in the list? "+
				cityList.contains("Miami"));
		System.out.println("The location of Denver in the list? "+
				cityList.indexOf("Denver"));
		System.out.println("Is the list empty? "+
				cityList.isEmpty());
		
		cityList.add(0,"Xian");
		cityList.remove("London");
		System.out.println(cityList.toString());
		
		int i;
		for(i=cityList.size()-1;i>=0;i--)
			System.out.print(cityList.get(i)+", ");
		System.out.println();
		
		ArrayList<CircleFromGenericGeometric> circles=new ArrayList<>();
		
		circles.add(new CircleFromGenericGeometric(4));
		System.out.println(circles.get(0).getArea());
		
		String[] array= {"red","green","blue"};
		ArrayList<String> list=new ArrayList<>(Arrays.asList(array));
		System.out.println(list.toString());
		java.util.Collections.shuffle(list);
		System.out.println(list);
	}
	

}
