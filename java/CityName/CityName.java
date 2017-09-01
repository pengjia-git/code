import java.util.*;
public class CityName {
	public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		String city1=input.nextLine();
		String city2=input.nextLine();
		if(city1.compareToIgnoreCase(city2) < 0)	
			System.out.println(city1+"\n"+city2);
		else
			System.out.println(city2+"\n"+city1);
	}
}
