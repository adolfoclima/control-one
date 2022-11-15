#pragma once
#include <config.h>

class Page_Tempos
{
private:
    static void TempoBase()
    {
        BaseDeTempoSeg = milles();
        BaseDeTempoSeg = BaseDeTempoSeg / 1000;
    }

    static void Tempo1seg()
    {
        if (BaseDeTempoSeg - previous1Seg >= 1)
        {
            previous1Seg = BaseDeTempoSeg;

            // if the LED is off turn it on and vice-versa:
            if (EstadoSeg == LOW)
            {
                EstadoSeg = HIGH;
            }
            else
            {
                EstadoSeg = LOW;
            }
            digitalWrite(PIN_LED_DEBUG, EstadoSeg);
        }
    }

public:
    static void Print()
    {
        TempoBase();
        Tempo1seg();
        // Exemplo2();
    }
};