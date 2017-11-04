import java.io.*;

public class JavaCopy {

	public static void main(String[] args) {
		try {
			byte[] buf=new byte[4*1024];
			int size;
			FileInputStream src=new FileInputStream("srcdata/src.dat");
			FileOutputStream dest=new FileOutputStream("dest.dat");
			do {
				size=src.read(buf);
				if(size <=0 )
					break;
				dest.write(buf,0,size);
			}while(true);
			src.close();
			dest.close();
			System.out.println("exit");
		}
		catch(EOFException e) {
			//src.close();
			return;
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

}
