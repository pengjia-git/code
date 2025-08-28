#include <iostream>
#include <stdlib.h>

class c_user_space{
	public:
		int size();
	private:
		int step=10*1024*1024;

	
};

int c_user_space::size()
{
	char *p;
	int space_size=0;
	
	while(1)
	{
		p=(char*)malloc(step);
		if(p)
		{
			space_size++;
		}
		else
			return space_size;
	}
}


int main()
{

	c_user_space a;
	std::cout<<a.size()<<std::endl;
	return 0;
}
