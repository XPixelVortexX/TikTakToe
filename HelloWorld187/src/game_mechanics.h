#ifndef game_mechanics_h
#define game_mechanics_h

#include <Arduino.h>
#include <stdio.h>
#include "swt_matrix.h"
#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"
#include "animations.h"

SWT* check_inputs();

int mode_select();

#endif