import java.awt.BorderLayout;
import java.awt.*;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JScrollPane;

public class TableTest {
	public static void main(String[] args) {
		JFrame.setDefaultLookAndFeelDecorated(true);
		JFrame frame = new JFrame("五子棋");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		String colume[]= {"1","2"};
//		Object[][] playerInfo= {{"1","2"},{"1","2"},{"1","2"}};
//		JTable table= new JTable(playerInfo,colume);
//		table.setPreferredScrollableViewportSize(new Dimension(300,300));
//		JScrollPane scrollPane = new JScrollPane(table);
		JPanel pnlPaint = new JPanel();
		pnlPaint.setBackground(Color.WHITE);
		pnlPaint.getGraphics().drawLine(0,0,100,100);
		frame.getContentPane().add(pnlPaint,BorderLayout.CENTER);
		frame.pack();
		frame.setVisible(true);
	}
}
