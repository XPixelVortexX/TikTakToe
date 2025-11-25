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
    Serial.printf("\n\n\n\n\nLevel %d erstellt. ",stage);
    Serial.printf("Mit der Nummer %d.\n\n",rand);
}

bool level_container::check()
{
    Serial.printf("Überprüfung beginnt.\n");
    for(int i=0; i<stage; i++)
    {
        if(container[i]->get_swt() != check_inputs())return false;
        Serial.printf("Richtige Antwort für Level %d\n",(i+1));
    }
    return (true);
}

void level::show()
{
    Serial.printf("LED %d leuchtet\n",my_led->pin);
    delay(TIME_OFF);
    my_led->on();
    delay(TIME_ON);
    my_led->off();
    
}

void level_container::show()
{
    for(int i=0; i<stage; i++)
    {
        container[i]->show();
    }
}