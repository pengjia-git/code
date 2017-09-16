import java.util.Calendar;
import java.util.GregorianCalendar;

public class Cloneable {

	public static void main(String[] args) {
		Calendar a1=new GregorianCalendar();
		Calendar a2=a1;
		Calendar a3=(Calendar)a1.clone();
//		System.out.println(a1 == a2);
		System.out.println(a1.toString()+":::"+a3.toString());
	}

}
