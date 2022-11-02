#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <Arduino.h>
#include <../lib/JC_Button/JC_Button.h> // https://github.com/JChristensen/JC_Button
#include <utils/MathLibrary.h>

// Declara todos os pins
const byte PIN_LED_1(2), // Led debug
    PIN_LED_2(12),
    PIN_BTN_1(34), // Burton 1
    PIN_BTN_2(35); // Button 2

// Declara os Buttons
Button Button_1(PIN_BTN_1, 25, false, false); // define the button
Button Button_2(PIN_BTN_2, 25, false, false); // define the button

// const int a = Add(10, 10);  // Chama função add da biblioteca
#endif
