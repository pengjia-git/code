
public class Roll {
	static int round_num=1;
	public static void main(String[] args) {
		if(game_engine_test())
			System.out.println("Test pass");
		else
			System.out.println("Test failure");
	}

	public static int game_engine(int dice1 ,int dice2)
	{

		int dice_sum=dice1+dice2;
		int last_dice_sum=0;
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
		if(game_engine(5	, 6) == 1)
			pass_num++;
		
		test_num++;
		if(game_engine(1,2) == 0)
			pass_num++;
		
		test_num++;
		if((game_engine(4,4) == 3) && (game_engine(6,2) == 1))
			pass_num++;
		
		test_num++;
		if((game_engine(3,2) == 3) && (game_engine(2,5) == 0))
			pass_num++;
		
		return test_num == pass_num;
	}
	
	public static double win_probability()
	{
		return 0.5;
	}
}
