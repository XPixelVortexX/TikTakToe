#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "ChipNorm_TM1637.h"

#include "level.h"

#define CLK_PIN 15
#define DIO_PIN 0

extern ChipNorm_TM1637 display;

void display_setup();
void update_score(level_container* p1,level_container* p2);

#endif
