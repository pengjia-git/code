import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;
import java.io.FileNotFoundException;
//import java.io.Exception;
import java.io.PrintWriter;
public class TestURL {

	public static void main(String[] args) 
	throws Exception
	{
		PrintWriter web_txt=new PrintWriter("url.html");
		try {
			URL url=new URL("https://www.hongxiu.com/chapter/7308157504504701/19617688659185927");
			Scanner webin=new Scanner(url.openStream());
			while(webin.hasNextLine()) {
				web_txt.print(webin.nextLine());
			}
			webin.close();
		}
		catch (MalformedURLException ex) {
			ex.printStackTrace();
		}
		
		
		web_txt.close();
		
	}

}
