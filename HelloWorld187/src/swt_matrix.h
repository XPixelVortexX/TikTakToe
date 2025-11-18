#ifndef swt_matrix_h
#define swt_matrix_h

#include <Arduino.h>
#include <stdio.h>

class SWT
{
    public:
        gpio_num_t pin;
        SWT(gpio_num_t pin): pin(pin){}
        bool read(){
            return gpio_get_level(pin);
        }
};

inline SWT* SWT0 = new SWT(GPIO_NUM_22);
inline SWT* SWT1 = new SWT(GPIO_NUM_21);
inline SWT* SWT2 = new SWT(GPIO_NUM_19);
inline SWT* SWT3 = new SWT(GPIO_NUM_4);
inline SWT* SWT4 = new SWT(GPIO_NUM_27);
inline SWT* SWT5 = new SWT(GPIO_NUM_35);
inline SWT* SWT6 = new SWT(GPIO_NUM_34);
inline SWT* SWT7 = new SWT(GPIO_NUM_39);
inline SWT* SWT8 = new SWT(GPIO_NUM_36);

inline SWT* SWT_MATRIX[9] = {SWT0,SWT1,SWT2,SWT3,SWT4,SWT5,SWT6,SWT7,SWT8};

#endif