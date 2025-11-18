#ifndef led_matrix_h
#define led_matrix_h

#include <Arduino.h>
#include <stdio.h>

class LED
{
    public:
        gpio_num_t pin;
        LED(gpio_num_t pin):pin(pin){}     
        
        void on(){
            gpio_set_level(pin,1);
        }

        void off(){
            gpio_set_level(pin,0);
        }

        void toggle(){
            if(gpio_get_level(pin)){
                gpio_set_level(pin,0);
            }
            else{
                gpio_set_level(pin,1);
            }
        }
};

inline LED* LED0 = new LED(GPIO_NUM_23);
inline LED* LED1 = new LED(GPIO_NUM_17);
inline LED* LED2 = new LED(GPIO_NUM_16);
inline LED* LED3 = new LED(GPIO_NUM_13);
inline LED* LED4 = new LED(GPIO_NUM_14);
inline LED* LED5 = new LED(GPIO_NUM_26);
inline LED* LED6 = new LED(GPIO_NUM_25);
inline LED* LED7 = new LED(GPIO_NUM_33);
inline LED* LED8 = new LED(GPIO_NUM_32);


inline LED* LED_MATRIX[9] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

inline void LED_MATRIX_ON()
{
    for (int i = 0; i < 9; i++) 
        {
            LED_MATRIX[i]->on();        
        }
}

inline void LED_MATRIX_OFF()
{
    for (int i = 0; i < 9; i++) 
        {
            LED_MATRIX[i]->off();        
        }
}

inline void LED_MATRIX_TOGGLE()
{
    for (int i = 0; i < 9; i++) 
        {
            LED_MATRIX[i]->toggle();        
        }
}

#endif