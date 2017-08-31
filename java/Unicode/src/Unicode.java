
public class Unicode {

	public static void main(String[] args) {
		char chinese='\u4e00';
		int i,j;
		System.out.printf("%x\n",(int)chinese);
		for(i=0;i<80;i++) {
			for(j=0;j<80;j++)
				System.out.print(chinese++);
			System.out.println("");
		}
	}

}
