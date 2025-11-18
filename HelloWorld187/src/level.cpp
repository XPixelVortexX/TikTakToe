#include "level.h"
#include "led_matrix.h"
#include "swt_matrix.h"
#include "gpio_setup.h"
#include "game_mechanics.h"

level::~level()
{
    //default
}

level_container::~level_container()
{
    for(int i=0;i<stage;i++)
    {
        delete container[i];
    }
}

SWT* level::get_swt()
{
    return my_swt;
}

void level_container::create_next()
{
    int rand = esp_random() % 8;
    container [stage] = new level(LED_MATRIX[rand],SWT_MATRIX[rand]);
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
    my_led->on();
    delay(TIME_ON);
    my_led->off();
    delay(TIME_OFF);
}

void level_container::show()
{
    for(int i=0; i<stage; i++)
    {
        container[i]->show();
    }
}