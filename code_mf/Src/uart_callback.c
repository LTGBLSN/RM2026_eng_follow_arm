//
// Created by 21481 on 2025/3/18.
//
#include "main.h"
#include "cmsis_os.h"
#include "can.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"

#include <stdio.h>
#include <string.h>
#include "board_LED.h"
#include "uart_printf.h"
#include "uart_sent.h"
#include "bus_servo.h"

// Size 参数是实际接收到的字节数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

    if (huart->Instance == USART1)
    {
        // 如果你想直接看数据，可以在这里打断点或者把数据转存
        // 比如：第一个字节是 servo_rx_buf[0], 应该是 '#'
        switch (servo_rx_buf[3])
        {
        case '0':
            servo00_angle = servo_data_get(servo_rx_buf[5], servo_rx_buf[6], servo_rx_buf[7], servo_rx_buf[8]);
            break;
        case '1':
            servo01_angle = servo_data_get(servo_rx_buf[5], servo_rx_buf[6], servo_rx_buf[7], servo_rx_buf[8]);
            break;
        case '2':
            servo02_angle = servo_data_get(servo_rx_buf[5], servo_rx_buf[6], servo_rx_buf[7], servo_rx_buf[8]);
            break;
        case '3':
            servo03_angle = servo_data_get(servo_rx_buf[5], servo_rx_buf[6], servo_rx_buf[7], servo_rx_buf[8]);
            break;
        case '4':
            servo04_angle = servo_data_get(servo_rx_buf[5], servo_rx_buf[6], servo_rx_buf[7], servo_rx_buf[8]);
            break;



        default:
            break;
        }

        HAL_UART_Receive_DMA(&huart1, servo_rx_buf, 10);
    }
}



