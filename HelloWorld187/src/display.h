#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "TM1637.h"

#define CLK 17
#define DIO 16

extern TM1637 display;

void display_setup();

#endif
