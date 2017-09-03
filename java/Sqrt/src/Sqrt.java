
public class Sqrt {

	public static void main(String[] args) {
		int i;
		
		for(i=0;i<1000000;i++) {
			double my_sqrt_num=sqrt(i);
			if(Math.abs(Math.sqrt(i) - my_sqrt_num) > 0.000001) {
				System.out.println("Wrong!"+i);
				break;
			}
		}
	}
	
	/* Babylonian method*/
	public static double sqrt(long n) {
		double nextGuess,lastGuess=1;
		while(true) {
			nextGuess=(lastGuess+ n/lastGuess)/2;
			if(Math.abs(nextGuess-lastGuess)<0.0000001)
				break;
			lastGuess=nextGuess;
		}
		return lastGuess;
	}
}
