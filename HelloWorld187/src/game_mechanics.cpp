#include "game_mechanics.h"
#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"

gpio_num_t* check_inputs() {
    for(int i=0; i<9;i++) {
        if(gpio_get_level(SWT_MATRIX[i])) return &SWT_MATRIX[i];
    }
    return nullptr;
}