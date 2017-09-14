import java.util.*;
public class TestCalendar {

	public static void main(String[] args) {
		GregorianCalendar cal=new GregorianCalendar();
		System.out.println(cal.get(Calendar.WEEK_OF_YEAR));
		System.out.println(365/7);
	}

}
