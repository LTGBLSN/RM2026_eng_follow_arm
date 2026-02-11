//
// Created by 21481 on 2025/3/24.
//
#include "main.h"
#include "cmsis_os.h"
#include "can.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"


#include <stdio.h>
#include "board_LED.h"
#include "uart_printf.h"
#include "uart_sent.h"
#include <math.h>
#include "refree_task.h"

void refree_task()
{
    while (1)
    {



        osDelay(1);
    }
}


