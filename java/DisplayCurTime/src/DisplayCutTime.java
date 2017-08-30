
public class DisplayCutTime {

	public static void main(String[] args) {
		long DAY_MILLS=24*60*60*1000;
		long HOUR_MILLS=1*60*60*1000;
		long MINUTE_MILLS=1*60*1000;
		long SECOND_MILLS=1*1000;
		long curmill=System.currentTimeMillis();
		long less=curmill%DAY_MILLS;
		long hour=less/HOUR_MILLS+8;
		less=less%HOUR_MILLS;
		long minute=less/MINUTE_MILLS;
		less=less%MINUTE_MILLS;
		long second=less/SECOND_MILLS;
		
		System.out.println("Current time "+hour+":"+minute+":"+second+" Bejing");
	}

}
