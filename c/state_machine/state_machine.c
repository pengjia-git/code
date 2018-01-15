#include <stdio.h>
#include <string.h>

typedef void (*sm_state_process)(int event);


static int cur_state_id;
sm_state_process *g_state_arry;

int sm_get_cur_state_id()
{
	return cur_state_id;
}


void sm_set_state_id(int id)
{
	cur_state_id=id;
}


void sm_reset(int init_id)
{
	sm_set_state_id(init_id);
}


int sm_init(int init_id,sm_state_process *state_arry) 
{
	sm_reset(init_id);
	g_state_arry=state_arry;
	return 0;
}


void sm_process(int event)
{
	int id;
	sm_state_process fun;

	id=sm_get_cur_state_id();
	fun=g_state_arry[id];
	if(fun)
		fun(event);
}


//test

typedef enum {
	PASSWORD_RIGHT=0,
	TIME_OUT,
	EVENT_MAX
}smart_lock_event_t;

typedef enum{
	CLOSE_DEPARTURE=0,
	CLOSE_JOIN,
	OPEN_JOIN,
}smart_lock_state_id;


void smart_lock_close_departure_process(int event)
{
	if(event != PASSWORD_RIGHT)
		return;
	printf("smart_lock_close_departure_process\n");
	sm_set_state_id(CLOSE_JOIN);
}


void smart_lock_close_join_process(int event)
{
	if(event != TIME_OUT)
		return;
	printf("smart_lock_close_join_process\n");
	sm_set_state_id(CLOSE_DEPARTURE);
}


sm_state_process state_fun_array[2]={
	smart_lock_close_departure_process,
	smart_lock_close_join_process
};

int main()
{
	char in[256];
	printf("hello\n");
	sm_init(CLOSE_DEPARTURE,state_fun_array);
	while(1){
		smart_lock_event_t event;
		memset(in,0,256);
		scanf("%s",in);
		if(strcmp(in,"password_right") == 0)
			event=PASSWORD_RIGHT;
		else if(strcmp(in,"time_out") == 0)
			event=TIME_OUT;
		else
			event=EVENT_MAX;
		sm_process(event);
	}
	return 0;
}