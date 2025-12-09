#include <Arduino.h>
#include <stdio.h>

#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"
#include "level.h"
#include "game_mechanics.h"
#include "animations.h"
#include "display.h"

level_container* Game;
level_container* Player1;
level_container* Player2;

void setup() {
  Serial.begin(115200);
  setup_pins();
  display_setup();
  //setup_ring();
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
    update_score(Game,nullptr);
    
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
    update_score(Player1,Player2);                       
    
    Player1->show();                                     

    if(!Player1->check())break;

    Player2->create_next();
    update_score(Player1,Player2);                         
    
    Player2->show();                                     

    if(!Player2->check())break;                       
  }

  anim_fail();
  delete Player1;
  delete Player2;
}

void loop() {
  int sel = mode_select();        //Idle

  //test();

  if(sel == 0) normal_game();
  if(sel == 1) mult_game();
  if(sel == 2) anim_eyer();
}