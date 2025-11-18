#ifndef level_h
#define level_h

#include <Arduino.h>
#include <stdio.h>
#include "swt_matrix.h"
#include "led_matrix.h"

#define TIME_ON 500
#define TIME_OFF 1000

class level {
    private:
        LED* my_led;
        SWT* my_swt;
        bool led_value;
        bool stw_value;
    
    public:
        level(LED* my_led = LED0, SWT* my_swt = SWT0): my_led(my_led),my_swt(my_swt){}
        virtual ~level();

        SWT* get_swt();

        virtual void show();
};

class level_container : level {
    public:
        int stage = 0;
        level* container [99];

        ~level_container();

        void create_next();
        void show();
        bool check();
};

#endif