#include "game_mechanics.h"
#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"

SWT* check_inputs() {
    for(int i=0; i<9;i++) {
        if(SWT_MATRIX[i]->read())
        {
            delay(50);
            return SWT_MATRIX[i];
        }
    }
    return nullptr;
}