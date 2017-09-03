
public class Roll {
	static int round_num=1;
	static int last_dice_sum=0;
	public static void main(String[] args) {
		if(game_engine_test())
			System.out.println("Test pass");
		else
			System.out.println("Test failure");
		System.out.println(win_probability());
	}

	public static int game_engine(int dice1 ,int dice2)
	{

		int dice_sum=dice1+dice2;
		int ret;
		
		if(round_num == 1) {
			switch(dice_sum) {
			case 2:
			case 3:
			case 12:
				ret=0;
				round_num=1;
				break;
			case 7:
			case 11:
				ret=1;
				round_num=1;
				break;
			default:
				ret=2;
				round_num++;
				last_dice_sum=dice_sum;
				break;
			}
		}
		else {
			if(dice_sum == 7) {
				ret=0;
				round_num=1;
			}
			else if(dice_sum == last_dice_sum) {
				ret=1;
				round_num=1;
			}
			else {
				ret=2;
				round_num++;
				last_dice_sum=dice_sum;
			}
		}
		
		return ret;
	}
	
	public static boolean game_engine_test()
	{
		int pass_num=0;
		int test_num=0;
		
		test_num++;
		if(game_engine(5, 6) == 1)
			pass_num++;
		
		test_num++;
		if(game_engine(1,2) == 0)
			pass_num++;
		
		test_num++;
		if((game_engine(4,4) == 2) && (game_engine(6,2) == 1))
			pass_num++;
		
		test_num++;
		if((game_engine(3,2) == 2) && (game_engine(2,5) == 0))
			pass_num++;
		
		return test_num == pass_num;
	}
	
	public static double win_probability()
	{
		int dice1,dice2;
		int i;
		int win_count=0,fail_count=0;
		int result;
		
		for(i=0;i<100000*1000;i++) {
			dice1=(int)Math.ceil(Math.random()*6);
			dice2=(int)Math.ceil(Math.random()*6);
			result=game_engine(dice1, dice2);
			
			if(result == 0)
				fail_count++;
			else if(result == 1)
				win_count++;
		}
		return (double)win_count/(double)(win_count+fail_count);
	}
}
