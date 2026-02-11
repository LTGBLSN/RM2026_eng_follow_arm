/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放蜂鸣器BEEP相关的函数
	*	@函数列表：
	*	1.	void beep_init(void) -- 初始化蜂鸣器BEEP
	*	2.	void BEEP_F(void) -- 翻转蜂鸣器BEEP
 ****************************************************************************/
 
#include "z_beep.h"

/***********************************************
	函数名称:	beep_init() 
	功能介绍:	初始化蜂鸣器BEEP
	函数参数:	无
	返回值:		无
 ***********************************************/
void beep_init(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = BEEP_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BEEP_GPIO_Port, &GPIO_InitStructure);
}

/***********************************************
	函数名称:	BEEP_F() 
	功能介绍:	翻转蜂鸣器BEEP
	函数参数:	无
	返回值:		无
 ***********************************************/
void BEEP_F(void) {
	if(BEEP==0)	
		BEEP_L();
	else 
		BEEP_H();
}
