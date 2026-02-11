//
// Created by 21481 on 2026/2/1.
//

#ifndef BUBING_RM2025_BUS_SERVO_H
#define BUBING_RM2025_BUS_SERVO_H

#include "main.h"

void usart1_printf(const char *fmt, ...);

void uart1_send_str(uint8_t *s);

int16_t servo_data_get( uint8_t data01 , uint8_t data02 , uint8_t data03 , uint8_t data04);

#endif //BUBING_RM2025_BUS_SERVO_H
