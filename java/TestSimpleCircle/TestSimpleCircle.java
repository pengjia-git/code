public class TestSimpleCircle{
	public static void main(String[] args){
		SimpleCircle circle1=new SimpleCircle();
		System.out.println("Nothing to do");
	}
}

class SimpleCircle{
	double radius;
	
	SimpleCircle(){
		System.out.println("default creation methord");
		radius=0;
	}

	SimpleCircle(double newRadius){
		System.out.println("creation methord");
		radius=newRadius;
	}
}
