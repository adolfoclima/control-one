#pragma once
#include <config.h>

class Page_Monitor
{
private:
    static void AtualizaMonitor()
    {
    }

    static void Exemplo2()
    {
        //
    }

public:
    static void Print()
    {

        if (tela == 0)
        {
            tela = 1;
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(0, 1);
            Display::lcd.print(Funcao);
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("F4:Home");
        }
        AtualizaMonitor();
        if (EstadoAnt != EstadoSeg)
        {
            Vlr = String(EstadoSeg); // BaseDeTempoSeg);
            Msg = Vlr + " L/dia";
            Display::lcd.setCursor(0, 0);
            Display::lcd.print(Msg);
            EstadoAnt = EstadoSeg;
        }
    }
};