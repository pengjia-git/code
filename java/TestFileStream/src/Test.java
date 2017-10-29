import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Test {

	public static void main(String[] args) {
		try {
		FileOutputStream out=new FileOutputStream("temp.txt");
		for(int i=1;i<5;i++)
			out.write(i);
		out.flush();
		out.close();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		
		try{
			int size;
			byte buf[]=new byte[20];
			FileInputStream input=new FileInputStream("temp.txt");
			size=input.read(buf);
			input.close();
			System.out.println(size);
			for(int i=0;i<size;i++)
				System.out.println(buf[i]);
			
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

}
