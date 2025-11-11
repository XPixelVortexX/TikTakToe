#include <Arduino.h>
#include <stdio.h>

#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"
#include "level.h"
#include "game_mechanics.h"

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

      gpio_set_level(LED_MATRIX[i],value);
      pressed = gpio_get_level(SWT_MATRIX[i]);

      Serial.printf("Pressed: %d\n",pressed);
    }
    value = !value;
  }
}

void game_loop() {
  while(true){
  gpio_num_t* current_input = nullptr;

  Game->create_next();                              //Level update
  
  for(int i=0;i<Game->get_stage();i++) {           
    while(current_input = nullptr) {                //Wait for input
      current_input = check_inputs();
    }
    if(!Game->check(current_input,i))return;        //fail is restart   
  }
  }
}

void loop() {
  //test();

  Game = new level_container();
  game_loop();
  delete Game;
}