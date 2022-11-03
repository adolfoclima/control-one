#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

#include <config.h>
#include <pages/Pages.h>

void setup()
{
    // Criando Buttons
    BtnFuncao1.begin(); // initialize the button object
    BtnFuncao2.begin(); // initialize the button object

    // Setup de saída
    pinMode(PIN_LED_DEBUG, OUTPUT);
    pinMode(PIN_BOMBA_CONTATOR, OUTPUT);
    pinMode(PIN_PRESSURIZADOR_CONTATOR, OUTPUT);

    // Setup de entrada
    pinMode(PIN_BOMBA_CORRENTE, INPUT); // Entrada analogica

    // Tela de Display
    Pages::splash.Print();
    Pages::home.Print();    
}
#endif