import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JOptionPane;


public class WuziqiEngine extends WuziqiGraphic{
	private static final long serialVersionUID = 5477256009375857161L;
	int steps=0;
	int[][] positions;
	private int blackCount=0;
	private int whiteCount=0;
	public WuziqiEngine() {
		positions=new int[checkerNumber][checkerNumber];
		for(int i=0;i<checkerNumber;i++)
			for(int j=0;j<checkerNumber;j++)
				positions[i][j]=0;
		
	    this.addMouseListener(new MouseAdapter(){  //匿名内部类，鼠标事件
	        public void mouseClicked(MouseEvent e){   //鼠标完成点击事件
	            if(e.getButton() == MouseEvent.BUTTON1){ //e.getButton就会返回点鼠标的那个键，左键还是右健，3代表右键
	                int x = e.getX();  //得到鼠标x坐标
	                int y = e.getY();  //得到鼠标y坐标
	                String banner = "鼠标当前点击位置的坐标是" + x + "," + y;
	                //System.out.println(banner);
	                int posx=(x-boardx)/checkerWidth;
	                int posy=(y-boardy)/checkerWidth;
	                if(	(posx > 0) && (posy > 0) &&
	                		(posx < checkerNumber) && (posy < checkerNumber)) {
		                if(steps%2 == 0) {
		                		positions[posx][posy]=1;
		                		drawChese(posx,posy,"black");
		                }
		                else {
		                		positions[posx][posy]=2;
		                		drawChese(posx, posy, "white");
		                }
		                steps++;
		                int result=isWin();
		                if(result != 0) {
		                		System.out.println("Game over");
		                		String message;
		                		if(result == 1)
		                			message="black win";
		                		else
		                			message="white win";
		                		show_dialog(message);
		                }
	                }
	            }
	        }
	    });
	}
	
	//黑子赢返回1，白子赢返回2，暂时没有赢家返回0
	int isWin()
	{
		boolean startFlag;
		int ret;
		int i;
		//横向检测
		for(int y=0;y<checkerNumber;y++) {
			startFlag=true;
			for(int x=0;x<checkerNumber;x++) {
				ret=hasFive(positions[x][y],startFlag);
				if(ret != 0)
					return ret;
				startFlag=false;
			}
		}
		//纵向检测
		for(int x=0;x<checkerNumber;x++) {
			startFlag=true;
			for(int y=0;y<checkerNumber;y++) {
				ret=hasFive(positions[x][y],startFlag);
				if(ret != 0)
					return ret;
				startFlag=false;
			}
		}
		//斜线检测
		for(i=0;i<checkerNumber;i++) {
			startFlag=true;
			for(int x=0;;x++) {
				int y=-1*x+i;
				if(y < 0) 
					break;
				ret=hasFive(positions[x][y],startFlag);
				if(ret != 0)
					return ret;
				startFlag=false;
			}
		}
		
		for(;i<2*checkerNumber;i++) {

			startFlag=true;
			for(int x=i-checkerNumber+1;x<checkerNumber;x++) {
				int y=-1*x+i;
				ret=hasFive(positions[x][y],startFlag);
				if(ret != 0)
					return ret;
				startFlag=false;
			}
		
		}
		//反斜线检测
		for(i=0;i<checkerNumber;i++) {
			startFlag=true;
			for(int x=0;x<checkerNumber;x++) {
				int y=x+14-i;
				if(y >= checkerNumber)
					break;
				ret=hasFive(positions[x][y],startFlag);
				if(ret != 0)
					return ret;
				startFlag=false;
			}
		}
		
		for(;i<2*checkerNumber;i++) {

			startFlag=true;
			for(int y=0;y<checkerNumber;y++) {
				int x=y-14+i;
				if(x >= checkerNumber)
					break;
				ret=hasFive(positions[x][y],startFlag);
				if(ret != 0)
					return ret;
				startFlag=false;
			}
		
		}
		return 0;
	}
	
	//无子为0，黑子为1，白子为2
	int hasFive(int x,boolean startFlag)
	{	
		int ret=0;
		
		if(startFlag) {
			blackCount=0;
			whiteCount=0;
		}
		
		if(x == 0) {
			blackCount=0;
			whiteCount=0;
		}
		else if(x == 1 )
			blackCount++;
		else if(x == 2)
			whiteCount++;
		if(blackCount == 5)
			ret=1;
		else if(whiteCount == 5)
			ret=2;
		
		return ret;
	}
	
	void show_dialog(String message)
	{
		int isStartAgin = JOptionPane.showConfirmDialog(this, "Game over:"+message,"是否重玩",
				JOptionPane.YES_NO_OPTION);
		if(isStartAgin == JOptionPane.YES_OPTION) {
			System.exit(0);
		}
		else {
			System.exit(0);
		}
	}
}
