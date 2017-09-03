
public class LargerThanAverage {

	public static void main(String[] args) {
		double[] array= new double[100];
		int i;
		for(i=0;i<array.length;i++)
			array[i]=100*Math.random();
		displayLarger(array);
	}
	
	public static void displayLarger(double[] array)
	{
		int i;
		double average=0;
		int len=array.length;
		
		for(i=0;i<len;i++)
			average+=array[i]/len;
		
		System.out.println("Following data is larger than average\n");
		for(i=0;i<len;i++) {
			if(array[i] > average)
				System.out.printf("array[%d]=%f\n",i,array[i]);
		}
	}
}
