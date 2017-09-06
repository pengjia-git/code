
public class ImmutableClass {

	public static void main(String[] args) {
		int[] a;
		int[] b= {1,2,3}; 
		ImmutableClass im=new ImmutableClass();
		a=im.getValue();
		a.toString()
		
	}
	private int[] value;
	public int[] getValue()
	{
		return value;
	}
}
