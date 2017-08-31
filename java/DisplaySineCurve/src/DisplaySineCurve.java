/*show a sine cure in terminal in a 20*80 rectangle*/
public class DisplaySineCurve {
	public static void main(String[] args) {
		int i,j;
		double real_y,tar_y;
		for(i=0;i<20;i++) {
			tar_y=-2.0/20*(i+1);
			System.out.printf("%2f",tar_y);
			for(j=0;j<80;j++) {
				real_y=Math.sin(Math.toRadians(j*360.0/80.0))-1.0;
				if(Math.abs(real_y-tar_y) < 0.05)
					System.out.print("*");
				else
					System.out.print("-");
			}
			System.out.println("");
		}
	}
}
