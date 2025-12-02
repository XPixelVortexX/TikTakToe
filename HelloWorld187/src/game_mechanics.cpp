#include "game_mechanics.h"

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

int mode_select() {
    int res = -1;
    int last_value = millis();
    while(!SEL->read())   //mode Button
    {
        if((millis()-last_value) > 2000){
            last_value = millis();
            display.clear();
            
            res++;
            if(res>=3)res=0;
            
            if(res == 0) P1_anim();
            if(res == 1) P1P2_anim();
            if(res == 2)display.write_text(E,A,R,R);
        }
    }
    return res;
}