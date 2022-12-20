#pragma once
#include <config.h>

class Page_Bip
{
private:
    static void Bip1()
    {
    }

public:
    static void Print()
    {
        // Monitora nível crítico
        Flag= digitalRead(PIN_SENSOR_NIVEL_CRITICO);
        if (Flag == HIGH)
        {
            Alarme = 1;
        }
        else
        {
            Alarme = 0;
        }

        // Escaneia alarmes
        switch (Alarme)
        {
        case 0:

            break;
        case 1:
            Msg = "Nivel critico!";
            break;
        case 2:

            break;
        default:

            break;
        }

        // Imprime na tela
        Display::lcd.setCursor(0, 0);
        Display::lcd.print(Msg);
    }
    /*
    Frequência das notas:
    Dó - 262 Hz
    Ré - 294 Hz
    Mi - 330 Hz
    Fá - 349 Hz
    Sol - 392 Hz
    Lá - 440 Hz
    Si - 494 Hz
    #Dó - 528 Hz
    */
};