//
// Created by 21481 on 2025/3/16.
//

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "cmsis_os.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"
#include "uart_printf.h"
#include "uart_sent.h"
#include "bus_servo.h"


void uart_sent_debug()
{
    while (1)
    {
        usart6_printf("%d,%d,%d,%d,%d \r\n",
                      servo00_angle,
                      servo01_angle,
                      servo02_angle,
                      servo03_angle,
                      servo04_angle);




        osDelay(1);




    }

}


void servo_uart_sent()
{
    while (1)
    {
        uart1_send_str((uint8_t *)"#001PRAD!");
        osDelay(5);
        uart1_send_str((uint8_t *)"#002PRAD!");
        osDelay(5);
        uart1_send_str((uint8_t *)"#003PRAD!");
        osDelay(5);
        uart1_send_str((uint8_t *)"#004PRAD!");
        osDelay(5);
    }
}




