#ifndef LOOP_H_INCLUDED
#define LOOP_H_INCLUDED

#include <config.h>
#include <pages/Pages.h>

void loop()
{
    // Leitura dos botoes
    BtnFuncao1.read(); // read the button
    BtnFuncao2.read(); // read the button
    BtnFuncao3.read(); // read the button
    BtnFuncao4.read(); // read the button

    // Açao botao F1
    if (BtnFuncao1.wasPressed()) // if the button was released, change the LED state
    {
        Pages::Monitor.Print();
    }
    // Açao botao F2
    if (BtnFuncao2.wasPressed()) // if the button was released, change the LED state
    {
        if (tela == 0)
        {
            Pages::Automatico.Print();
        }
    }
    // Açao botao F3
    if (BtnFuncao3.wasPressed()) // if the button was released, change the LED state
    {
        if (tela == 0)
        {
            Pages::Jardim.Print();
        }
    }
    // Açao botao F4
    if (BtnFuncao4.wasPressed()) // if the button was released, change the LED state
    {
        switch (tela)
        {
        case 0: // tela Home
            Pages::Desliga.Print();
            break;
        default:
            Pages::Home.Print();
            break;
        }
    }
    // if (Button_1.wasReleased()) // if the button was released, change the LED state
    // {
    //   ledState = !ledState;
    //   digitalWrite(PIN_LED_1, ledState);
    // }

    // if (Button_1.pressedFor(2000))
    // {
    //   // button has been pressed for one second
    //   digitalWrite(PIN_LED_1, true);
    // }

    // if (Button_2.pressedFor(2000))
    // {
    //   // button has been pressed for one second
    //   digitalWrite(PIN_LED_1, false);
    // }
}
#endif