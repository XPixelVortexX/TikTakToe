#include <Arduino.h>
#include <stdio.h>

#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"
#include "level.h"
#include "game_mechanics.h"
#include "animations.h"

level_container* Game;

void setup() {
  Serial.begin(9600);
  setup_pins();
}

void test()
{
  bool value = 0;
  bool pressed =0;

  while(1){
    for(int i=0;i<9;i++){
      delay(500);

      Serial.printf("PIN: %d  ",i);
      Serial.printf("Value: %d  ",value);

      LED_MATRIX[i]->toggle();

      pressed = SWT_MATRIX[i]->read();

      Serial.printf("Pressed: %d\n",pressed);
    }
    value != value;
  }
}

void game_loop() {
  while(true){
  Game->create_next();                              //Level update
    
  if(!Game->check())return;                         //fail is restart   
  }
}

void loop() {
  //test();

  Game = new level_container();
  game_loop();
  delete Game;
}