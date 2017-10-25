import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;

import javax.swing.JFrame;

public class WuziqiGraphic extends JFrame{
	protected int boardx,boardy;
	protected int checkerWidth,checkerNumber;
	private Color boardColor;
	private int cheseWidth;
	
	public WuziqiGraphic()
	{
		boardx=50;
		boardy=50;
		checkerWidth=40;
		checkerNumber=15;
		boardColor=new Color(238,232,170);
		cheseWidth=30;
	}
	
	public void drawBoard()
	{
		Graphics g;
		Container p = getContentPane();
		setBounds(boardx, boardy, checkerWidth*checkerNumber+boardx*2, 
				checkerWidth*checkerNumber+boardy*2);
		setVisible(true);
		p.setBackground(boardColor);
		setLayout(null);   
		setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);        
		
		try {
		    Thread.sleep(100);
		} catch (Exception e) {
		    e.printStackTrace();
		}        
		
		// 获取专门用于在窗口界面上绘图的对象
		g =  this.getGraphics();
		try {
            // 设置线条颜色为红色
            g.setColor(Color.BLACK);
            
            for(int i = 0; i < checkerNumber+1; i ++) {
                // 绘制竖直线
                g.drawLine(boardx+i*checkerWidth,boardy,
                		boardx+i*checkerWidth,boardy+checkerWidth*checkerNumber);
                
                // 绘制水平线
                g.drawLine(boardx,boardy+i*checkerWidth,
                		boardx+checkerNumber*checkerWidth,boardy+i*checkerWidth);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
	}
	
	public void drawChese(int x,int y,String cheseType)
	{
		if((x >= checkerNumber) || (y >= checkerNumber))
			return;
		
		if((cheseType.equalsIgnoreCase("white") == false) && 
				(cheseType.equalsIgnoreCase("black") == false))
			return;
		
		int chesex=boardx+(checkerWidth-cheseWidth)/2+x*checkerWidth;
		int chesey=boardy+(checkerWidth-cheseWidth)/2+y*checkerWidth;
		
		Graphics g=this.getGraphics();;
		Color oldColor=g.getColor();
		if(cheseType.equalsIgnoreCase("white"))
			g.setColor(Color.WHITE);
		else if(cheseType.equalsIgnoreCase("black"))
			g.setColor(Color.BLACK);
		else 
			return;
		
        g.drawOval(chesex,chesey,cheseWidth,cheseWidth);
        g.fillOval(chesex,chesey,cheseWidth,cheseWidth);
        g.setColor(oldColor);
	}
	
}
