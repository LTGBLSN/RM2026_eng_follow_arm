//
// Created by 21481 on 2026/2/1.
//


#include "bus_servo.h"
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include "string.h"

/**********************************************
	* @总线设备基本控制指令表：
 * #000PCSM!
 * #000PRAD!
 * #000PSCK!
	*	1.	#000PID!						//读取ID指令
	*	2.	#000PID001!						//设置ID指令
	*	3.	#000PVER!						//读取版本
	*	4.	#000PBD1!						//设置波特率 默认115200  1:9600 , 2:19200 , 3:38400 , 4:57600 , 5:115200 , 6:128000 7:256000  8:1000000
	*	5.	#000PCLE!						//恢复出厂设置包括ID
	* @总线舵机ZServo控制指令表：
	*	1.	#000P1500T1000!					//舵机角度控制
	*	2.	#000PDST!						//停止
	*	3.	#000PDPT!						//暂停
	*	4.	#000PDCT!						//继续
	*	5.	#000PCSD!						//设置当前值为开机值
	*	6.	#000PCSM!						//开机释放扭力
	*	7.	#000PRAD!						//读取角度
	*	8.	#000PULK!						//释力
	*	9.	#000PULR!						//恢复扭力
	*	10.	#000PSCK!						//设置当前值为1500的偏差值
	*	11.	#000PSCK+050!					//把1500+50作为1500的中间值
	*	12.	#000PSCK-050!					//把1500-50作为1500的中间值
	*	13.	#000PMOD!						//读取模式
	*	14.	#000PMOD1!						//设置模式 舵机模式：
 *	2 270 逆时针
 *	1：270 顺
 *	4 180 逆时针
 *	3：180 顺
 *	马达模式：6 360 逆时针
 *	5：360 顺圈
 *	8 360 逆时针
 *	7：360 顺时
	*	15.	#000PRTV!						//读取电压和温度
	*	16.	#000PSTB!						//读取保护值
	*	17.	#000PSTB=60!					//设置保护值 默认60 范围25-80
	*	18.	#000PPAAAIBBB!					//设置KP = AAA, KI = BBB
	*	19.	#000PMIN!						//设置最小值
	*	20.	#000PMAX!						//设置最大值
	*	21.	#000PULM! 						//释力 不带阻力
	*	22.	#000PLN!						//RGB灯开启
	*	23.	#000PLF!						//RGB灯关闭
 **********************************************/

extern UART_HandleTypeDef huart1;

void uart1_send_str(uint8_t *s)
{
    // 原代码中的 close 和 open 可能是为了关闭中断防止干扰
    // 在 HAL 中，如果只是简单的阻塞发送，可以直接调用：
    HAL_UART_Transmit(&huart1, s, strlen((char *)s), HAL_MAX_DELAY);
}

int16_t servo_data_get( uint8_t data01 , uint8_t data02 , uint8_t data03 , uint8_t data04)
{
    int16_t servo_pos = 1500;
    servo_pos = (data01 - '0') * 1000 +
                (data02 - '0') * 100  +
                (data03 - '0') * 10   +
                (data04 - '0');

    return servo_pos;
}








