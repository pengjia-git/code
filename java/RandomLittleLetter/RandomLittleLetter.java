public class RandomLittleLetter{
	public static void main(String[] args){
		char begine_little_letter='a';
		int i;
		for(i=0;i<10000;i++){
			int increase=(int)(Math.random()*26);
			char random_char=(char)(begine_little_letter+increase);
			//System.out.print(random_char);
			if( !Character.isLowerCase(random_char))
				System.out.println("Has an error");
		}
	}
}
