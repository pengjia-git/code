package lottery;
import java.util.Scanner;
public class Lottery {

	public static void main(String[] args) {
		int winning_flag=0;
		int i,same_digit_num=0;
		String winning_num=(int)(Math.random()*100)+"";
		//System.out.println(winning_num);
		
		Scanner input=new Scanner(System.in);
		String customer_num=input.nextLine();
		if(customer_num.length() != 2) {
			input.close();
			return;
		}
			
		if(winning_num.equals(customer_num))
			winning_flag|=1;
		for(i=0;i<2;i++) {
			String customer_char=customer_num.substring(i,i+1);
			if(winning_num.contains(customer_char))
				same_digit_num++;
		}
		if(same_digit_num == 2)
			winning_flag|=2;
		else if(same_digit_num == 1)
			winning_flag|=4;
		
		System.out.println("�н����룺"+winning_num);
		if((winning_flag & 0x01) != 0)
			System.out.println("����һ�Ƚ� 10 000��");
		else if((winning_flag & 0x02) != 0)
			System.out.println("���˶��Ƚ� 3000��");
		else if((winning_flag & 0x04) != 0)
			System.out.println("�������Ƚ� 1000��");
		else
			System.out.println("δ�н�");

		input.close();
	}

}
