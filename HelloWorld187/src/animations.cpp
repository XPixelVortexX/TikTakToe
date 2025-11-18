#include "animations.h"

void anim_fail()
{
    for(int i = 0; i < 6; i++)
    {
        LED_MATRIX_TOGGLE();
        delay(100);
    }
    LED_MATRIX_OFF();    
}

void anim_normal_game()
{
    for(int j = 0; j < 4; j++){
        for (int i = 0; i <= 8; i++) 
        {
            if (i == 4) continue;
            LED_MATRIX[i]->toggle();        
        }
        delay(200);
    }
    LED_MATRIX_OFF();
}

void anim_mult_game()
{
    int left [5] = {0,1,3,6,7};
    int right [5] = {1,2,5,7,8};

    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            LED_MATRIX[left[i]]->toggle();
        }
        for(int i = 0; i < 5; i++)
        {
            LED_MATRIX[right[i]]->toggle();
        }
    }
}
