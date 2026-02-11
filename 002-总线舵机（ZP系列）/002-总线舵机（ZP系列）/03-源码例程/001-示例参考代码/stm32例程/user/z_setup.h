/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
 ****************************************************************************/

#ifndef __SETUP_H__
#define __SETUP_H__

/*******初始化函数声明*******/

#include "z_main.h"
#include "z_timer.h" 
#include "z_uart.h"
#include "z_delay.h"
#include "z_led.h"
#include "z_beep.h"

/*******初始化函数声明*******/
void setup_systick(void);	//初始化滴答时钟，1ms增加一次systick_ms的值
void setup_led(void);		//初始化信号灯
void setup_beep(void);		//初始化蜂鸣器
void setup_uart1(void);		//初始化串口1
void setup_uart3(void);		//初始化串口2
void setup_finish(void);	//初始化完成

#endif
