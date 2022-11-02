#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

#include <config.h>

void setup()
{
    // Criando Buttons
    Button_1.begin();           // initialize the button object
    Button_2.begin();           // initialize the button object

    // Create Leds
    pinMode(PIN_LED_1, OUTPUT); // set the LED pin as an output
}
#endif