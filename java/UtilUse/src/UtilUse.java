import java.util.Date;
public class UtilUse {

	public static void main(String[] args) {
		int i;
		double sum=0;
		Date date=new Date();
		System.out.println(date.toString());
		System.out.println(date.getTime());
		for(i=0;i<100;i++)
			sum+=Math.pow(2.3,i);
		System.out.println(date.toString());
		System.out.println(date.getTime());
		System.out.println(sum);
	}

}
