#include "display.h"

ChipNorm_TM1637 display(CLK_PIN,DIO_PIN);

void display_setup() {
    display.setBrightness(7);
    display.clear();
}

void update_score(level_container* p1,level_container* p2) {
    display.clear();
    if(p2 == nullptr) display.write_numbers(0,0,((p1->stage)/10) , ((p1->stage)%10));
    else display.write_numbers(((p1->stage)/10) , ((p1->stage)%10) , ((p2->stage)/10) , ((p2->stage)%10));
}

