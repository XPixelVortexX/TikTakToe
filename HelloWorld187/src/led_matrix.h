#ifndef led_matrix_h
#define led_matrix_h

#include <Arduino.h>
#include <stdio.h>

#define LED0 GPIO_NUM_23
#define LED1 GPIO_NUM_17
#define LED2 GPIO_NUM_16
#define LED3 GPIO_NUM_13
#define LED4 GPIO_NUM_14
#define LED5 GPIO_NUM_26
#define LED6 GPIO_NUM_25
#define LED7 GPIO_NUM_33
#define LED8 GPIO_NUM_32

const gpio_num_t LED_MATRIX[] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

#endif