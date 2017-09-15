
public class TestEdible {

	public static void main(String[] args) {
		Chicken c1=new Chicken();
		System.out.println(c1.howToEat());
		System.out.println(c1.sound());
		
		Apple a1=new Apple();
		System.out.println(a1.howToEat());
		
		Oragne o1=new Oragne();
		System.out.println(o1.howToEat());
	}

}

interface Edible{
	public  String howToEat();
}

abstract class Animal{
	public abstract String sound();
}

class Chicken extends Animal implements Edible{
	public String howToEat(){
		return "Chicken:Fry it";
	}
	
	public String sound() {
		return "GeDege";
	}
}


abstract class Fruit implements Edible{
	public  abstract String howToEat();
}

class Apple extends Fruit{
	public String howToEat()
	{
		return "Make apple cider";
	}
}

class Oragne extends Fruit{
	public String howToEat()
	{
		return "Make orange juice";
	}
}