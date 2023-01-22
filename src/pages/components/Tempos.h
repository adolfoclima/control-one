#pragma once
#include <LiquidCrystal_I2C.h>
#include <config.h>

class Page_Tempos
{
private:
    static void TempoBase()
    {
        BaseDeTempoSeg = milles();
        BaseDeTempoSeg = BaseDeTempoSeg / 1000;
    }

    static void TempoBaseMeio()
    {
        BaseDeTempoMeioSeg = milles();
        BaseDeTempoMeioSeg = BaseDeTempoMeioSeg / 500;
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

    static void TempoMeioSeg()
    {
        if (BaseDeTempoMeioSeg - PreviousMeioSeg >= 1)
        {
            PreviousMeioSeg = BaseDeTempoMeioSeg;
            // if the LED is off turn it on and vice-versa:
            if (EstadoMeioSeg == LOW)
            {
                EstadoMeioSeg = HIGH;
                ContadoresMeioSegundo();
            }
            else
            {
                EstadoMeioSeg = LOW;
                ContadoresMeioSegundo();
            }
        }
    }

    static void ContadoresMeioSegundo() // Acoes a cada meio segundo
    {
        if (Pressurizador.getStatus()) // Pressurizador esta acionado?
        {
            TempoPressurizador++;
        }

        if (Alarme)
        {
            TempoAlarme++;
        }

        
    }

    static void Relogio()
    {
        if (TempoBackLigth)
        {
            TempoBackLigth++; // Incrementa tempo do LCD aceso
        }
        SegAtual++;
        if (SegAtual > 59)
        {
            SegAtual = 0;
            MinAtual++;
            if (MinAtual > 59)
            {
                MinAtual = 0;
                HoraAtual++;
                if (HoraAtual > 23)
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

    static void ApagarDisplay()
    {
        if (TempoBackLigth > 400)
        {
            TempoBackLigth = 401;
            if (EstadoSeg)
            {
                Display::lcd.noBacklight();
            }
            else
            {
                Display::lcd.backlight();
            }
        }
        else if (TempoBackLigth > 30)
        {
            TempoBackLigth = 0;
            Display::lcd.noBacklight();
        }
        else if (TempoBackLigth > 1)
        {
            Display::lcd.backlight();
        }
        else
        {
        }
    }

public:
    static void Print()
    {
        ApagarDisplay();
        TempoBase();
        TempoUmseg();
        TempoBaseMeio();
        TempoMeioSeg();
    }
};