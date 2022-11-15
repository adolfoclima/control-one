#pragma once
#include <config.h>

class Page_Automatico
{
private:
    static void AtualizaLitragem()
    {

        // digitalWrite(PIN_BOMBA_CONTATOR, HIGH);
        // delay(200);
        // digitalWrite(PIN_BOMBA_CONTATOR, LOW);
    }

    static void ControleNivel()
    {
        // Ação Sensores de niveis
    }

    // PIN_SENSOR_NIVEL_SUPERIOR(25)
    // PIN_SENSOR_NIVEL_INFERIOR(26)
    // PIN_SENSOR_NIVEL_CRITICO(27)
public:
    static void Print()
    {
       /* if (TelaAtual != "DESL")
        {
            Vlr = String(BaseDeTempoSeg);
            Msg = Vlr + " L/dia";
            if (VlrAnt != Vlr)
            {
                VlrAnt = Vlr;
                Display::lcd.clear();
                Display::lcd.setCursor(0, 1);
                Display::lcd.print(Funcao);
                Display::lcd.setCursor(9, 1);
                Display::lcd.print("F4:Home");
                Display::lcd.setCursor(0, 0);
                Display::lcd.print(Msg);
                TelaAtual = "AUTO";
            }
        }*/
        // ControleNivel();
    }
};