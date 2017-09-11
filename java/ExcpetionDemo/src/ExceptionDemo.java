import java.util.InputMismatchException;
import java.util.Scanner;
public class ExceptionDemo {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		boolean inputcontinue=true;
		do {
			try {
				int a=input.nextInt();
				System.out.println(a);
				inputcontinue=false;
			}
			catch(InputMismatchException ex) {
				System.out.println("exception");
				input.nextLine();
			}
		}while(inputcontinue);
		input.close();
		System.out.println("End");
	}

}
