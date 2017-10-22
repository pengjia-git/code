

import java.awt.event.*;
import javax.swing.AbstractButton;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.swing.ImageIcon;

public class Wuziqi extends JPanel {
	JButton whiteChese,blackChese;
	public Wuziqi()
	{
		whiteChese=new JButton(createImageIcon("image/white_chese.png"));
		blackChese=new JButton(createImageIcon("image/black_chese.png"));
		add(whiteChese);
		add(blackChese);
	}
	
	protected static ImageIcon createImageIcon(String path) {
        java.net.URL imgURL = Wuziqi.class.getResource(path);
        System.out.println(imgURL.toString());
        if (imgURL != null) {
            return new ImageIcon(imgURL);
        } else {
        	System.out.println(System.getProperty("user.dir"));
            System.err.println("Couldn't find file: " + path);
            return null;
        }
    }
	
	public static void main(String[] args) {
		JFrame.setDefaultLookAndFeelDecorated(true);
		JFrame frame = new JFrame("五子棋");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Wuziqi newContentPane = new Wuziqi();
		newContentPane.setOpaque(true);
		frame.setContentPane(newContentPane);
		frame.pack();
		frame.setVisible(true);
	}
}
