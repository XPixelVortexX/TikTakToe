#include "display.h"

TM1637 display;   // wird HIER definiert

void display_setup() {
    display.begin(CLK, DIO, 4);
    display.setBrightness(7);
    display.displayClear();
    display.displayInt(1234);
}
