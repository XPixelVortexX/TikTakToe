#include <Arduino.h>
#include <stdio.h>

#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"
#include "level.h"
#include "game_mechanics.h"
#include "animations.h"

level_container* Game;
level_container* Player1;
level_container* Player2;

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
      Serial.printf("Value: %d  ",(int)value);

      LED_MATRIX[i]->toggle();

      pressed = SWT_MATRIX[i]->read();

      Serial.printf("Pressed: %d\n",pressed);
    }
    value = !value;
  }
}

void normal_game() {
  Game = new level_container();
  anim_normal_game();

  while(true){
    Game->create_next();                              // Level update
    
    Game->show();                                     // Show next level

    if(!Game->check())break;                          // Fail is restart   
  }

  anim_fail();
  delete Game;
}

void mult_game()
{
  Player1 = new level_container();
  Player2 = new level_container();
  anim_mult_game();

  while(true){
    Player1->create_next();                       
    
    Player1->show();                                     

    if(!Player1->check())break;

    Player2->create_next();                       
    
    Player2->show();                                     

    if(!Player2->check())break;                       
  }

  anim_fail();
  delete Player1;
  delete Player2;
}

void loop() {
  //test();

  normal_game();

  //mult_game();
}