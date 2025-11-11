#ifndef level_h
#define level_h

#include <Arduino.h>
#include <stdio.h>

class level {
    private:
        gpio_num_t my_led;
        gpio_num_t my_swt;
        bool led_value;
        bool stw_value;
    
    public:
        level(gpio_num_t my_led, gpio_num_t my_swt){
            led_value = 0;
            stw_value = 0;
        };

        bool get_value_swt();

        virtual void show();
};

class level_container : level {
    public:
        level_container();
        void create_next();
        void show();
        bool check(gpio_num_t* swt,int stage);
        int get_stage();
};

#endif