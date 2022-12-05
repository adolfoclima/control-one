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

    static void TempoUmseg()
    {
        if (BaseDeTempoSeg - previous1Seg >= 1)
        {
            previous1Seg = BaseDeTempoSeg;

            // if the LED is off turn it on and vice-versa:
            if (EstadoSeg == LOW)
            {
                EstadoSeg = HIGH;
                Relogio();
            }
            else
            {
                EstadoSeg = LOW;
                Relogio();
            }
            digitalWrite(PIN_LED_DEBUG, EstadoSeg);
        }
    }

    static void Relogio()
    {
        SegAtual++;
        if (SegAtual > 59)
        {
            SegAtual = 0;
            MinAtual++;
            if (MinAtual > 59)
            {
                MinAtual = 0;
                HoraAtual++;
                if (HoraAtual > 59)
                {
                    HoraAtual = 0;
                    // Ressetar o contador aqui
                }
            }
        }

        if (HoraAtual < 10)
        {
            SHoraAtual = " " + String(HoraAtual);
        }
        else
        {
            SHoraAtual = String(HoraAtual);
        }

        if (MinAtual < 10)
        {
            SMinAtual = "0" + String(MinAtual);
        }
        else
        {
            SMinAtual = String(MinAtual);
        }

        if (EstadoSeg)
        {
            SHoraAtual = SHoraAtual + ":" + SMinAtual;
        }
        else
        {
            SHoraAtual = SHoraAtual + " " + SMinAtual;
        }
    }

public:
    static void Print()
    {
        TempoBase();
        TempoUmseg();
    }
};