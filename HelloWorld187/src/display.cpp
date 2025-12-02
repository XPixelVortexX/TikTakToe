#include "display.h"


void display_setup() {
    ChipNorm_TM1637 display(CLK_PIN,DIO_PIN);
    display.setBrightness(7);
    display.clear();
    display.write_numbers(1,2,3,4);
}

void update_score(level_container* p1,level_container* p2) {
    display.clear();
    if(p2 == nullptr) display.write_numbers(0,0,((p1->stage)/10) , ((p1->stage)%10));
    else display.write_numbers(((p1->stage)/10) , ((p1->stage)%10) , ((p2->stage)/10) , ((p2->stage)%10));
}

