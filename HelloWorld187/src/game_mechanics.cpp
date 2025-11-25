#include "game_mechanics.h"
#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"

SWT* check_inputs() {
    int i = 0;
    while(true){
        if(SWT_MATRIX[i]->read())           //erster impuls
        {
            delay(50);                      //Schalterprellen
            while(SWT_MATRIX[i]->read()){}  //Falls gedrückt gehalten
            delay(50);                      //Schalterprellen nach halten
            return SWT_MATRIX[i];
        }
    i++;
    if(i==9)i=0;
    }
}