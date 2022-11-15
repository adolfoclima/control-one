#pragma once
#include <config.h>

class Page_Controle
{
private:
    static void ControleDeNivel()
    {
        // Ação Sensores de niveis
        FLAG = digitalRead(PIN_SENSOR_NIVEL_SUPERIOR);        
        if (FLAG == 1)
        {
            // digitalWrite(PIN_BOMBA_CONTATOR, LOW);
            Bomba.off();
        }
        else
        {
            // FLAG = digitalRead(PIN_SENSOR_NIVEL_INFERIOR);
            if (FLAG == 0)
            {
                // digitalWrite(PIN_BOMBA_CONTATOR, HIGH);
                Bomba.on();
            }
        }
    }

    // PIN_SENSOR_NIVEL_SUPERIOR(25)
    // PIN_SENSOR_NIVEL_INFERIOR(26)
    // PIN_SENSOR_NIVEL_CRITICO(27)
public:
    static void Nivel()
    {
        ControleDeNivel();
    }
};