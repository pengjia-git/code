import java.io.*;

public class Test {

	public static void main(String[] args) {
		try {
			DataOutputStream out=new DataOutputStream(new FileOutputStream("temp.bat"));
			out.writeUTF("pengjia");
			out.writeDouble(17.8);
			out.close();
			
			DataInputStream in=new DataInputStream(new FileInputStream("temp.bat"));
			BufferedOutputStream
			System.out.println(in.readUTF());
			System.out.println(in.readDouble());
			System.out.println(in.readUTF());
			in.close();
		}
		catch (EOFException e) {
			System.out.println("End of file");
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		
	}

}
