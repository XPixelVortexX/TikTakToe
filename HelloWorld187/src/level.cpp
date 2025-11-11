#include "level.h"
#include "led_matrix.h"
#include "swt_matrix.h"
#include "gpio_setup.h"
#include "game_mechanics.h"

gpio_num_t* level::get_swt()
{
    return &my_swt;
}

void level_container::create_next()
{
    container [stage] = new level(LED_MATRIX[1],SWT_MATRIX[1]);
    stage++;
}

bool level_container::check()
{
    for(int i=0; i<stage; i++)
    {
        if(container[i]->get_swt() != check_inputs())return false;
    }
    return (true);
}

void level::show()
{
    gpio_set_level(my_led,1);
    delay(TIME_ON);
    gpio_set_level(my_led,0);
    delay(TIME_OFF);
}

void level_container::show()
{
    for(int i=0; i<stage; i++)
    {
        container[i]->show();
    }
}