import java.util.Scanner;
public class GuessBirthday {

	public static void main(String[] args) {
		String table[]= {
				"1 3 5 7 \n"+
				"9 11 13 15\n"+
				"17 19 21 23\n"+
				"25 27 29 31",
				
				"2 3 6 7\n"+
				"10 11 14 15\n"+
				"18 19 22 23\n"+
				"26 27 30 31",
				
				"4 5 6 7\n"+
				"12 13 14 15\n"+
				"20 21 22 23\n"+
				"28 29 30 31",
				
				"8 9 10 11\n"+
				"12 13 14 15\n"+
				"24 25 26 27\n"+
				"28 29 30 31",
				
				"16 17 18 19\n"+
				"20 21 22 23\n"+
				"24 25 26 27\n"+
				"28 29 30 31"
			};
		
		int i,birthday=0;
		String first_num;
		String answer;
		Scanner input=new Scanner(System.in);
		for(i=0;i<5;i++) {
			int index;
			System.out.println(table[i]);
			System.out.println("Is there your birthday on this table?");
			answer=input.next();
			if(answer.equalsIgnoreCase("y") || 
					answer.equalsIgnoreCase("yes")) {
				index=table[i].indexOf(' ');
				first_num=table[i].substring(0, index);
				birthday+=Integer.parseInt(first_num);
			}
			System.out.print("\n");	
		}
		
		System.out.print("Your birthday is "+birthday);
		input.close();
	}

}
