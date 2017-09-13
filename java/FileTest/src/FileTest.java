import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
public class FileTest {

	public static void main(String[] args) 
	throws Exception{
		PrintWriter file=new PrintWriter("score.txt");
		file.print("jia in this file\n");
		file.close();
		File a=new File("score.txt");
		Scanner input=new Scanner(a);
		System.out.println(input.nextLine());
		input.close();
	}

}
