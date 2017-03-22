#include <linux/slab.h>

#include <linux/irq.h>

#include <linux/interrupt.h>

#include <linux/poll.h>

#include <asm/io.h>

#include <linux/delay.h>

#include <linux/module.h>

#include <linux/time.h>

#include <linux/gpio.h>

#include <linux/wait.h>

#include <linux/input.h>

#include <linux/init.h>
#include <linux/timer.h>

struct input_dev *btn_dev;      //input设备的结构体，这里定义了btn_de
static int __init button_init(void);
static void __exit button_exit(void);
struct timer_list test_timer;//=TIMER_INITIALIZER(input_timer,jiffies+HZ*1,(unsigned long)0 );
static int count=0;
void input_timer(unsigned long i)
{
	input_report_key(btn_dev, KEY_NUMERIC_0, 1);
	input_report_key(btn_dev, KEY_NUMERIC_0, 0);
	input_sync(btn_dev);
	printk("input timer jia %d\n",count++);
//    printk("%s/n", (char *)i);

//    mod_timer(&mytimer, jiffies + 2*HZ);
	test_timer.expires=3*HZ+jiffies;
	add_timer(&test_timer);
}
static int __init button_init(void)
{

	int error;

	//分配input设备

	btn_dev = input_allocate_device();

	if(!btn_dev)

	{

		printk(KERN_ERR "button: not enough memory\n");

		error = -ENOMEM;

//		goto err_free_irq;

	}

	__set_bit(EV_SYN, btn_dev->evbit);  //设置位
	    __set_bit(EV_KEY, btn_dev->evbit);  //设置一个按键类事件,表示能够产生按键事件。

	    __set_bit(KEY_NUMERIC_0, btn_dev->keybit);//表示能产生哪些按键

	//把相应的按键给置上

//	btn_dev->evbit[0] = BIT_MASK(EV_KEY);
//
//	btn_dev->keybit[BIT_WORK(KEY_NUMERIC_0)] |= BIT_MASK(KEY_NUMERIC_0);

	//注册input设备

	error = input_register_device(btn_dev);

	if(error)

	{

		printk(KERN_ERR "button: failed to register device\n");


	}

	//初始化工作队列

	//INIT_DELAYED_WORK(&power_work, power_work_fn);
	init_timer(&test_timer);
	test_timer.data=0;
	test_timer.function=input_timer;
	test_timer.expires=3*HZ+jiffies;
	printk("pengjia my_power button register ok\n");
	add_timer(&test_timer);
	return 0;

	err_free_dev:

	input_free_device(btn_dev);


	return error;

}

static void __exit button_exit(void)

{

	input_free_device(btn_dev);
	del_timer(&test_timer);
	//    free_irq(gpio_base+pow_btn, power_isr);

}

module_init( button_init);

module_exit( button_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("eastmoon");

