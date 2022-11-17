#pragma once
#include <config.h>

class Page_Monitor
{
private:
    static bool obterEstadoDoDisplay()
    {
        if (estadoDoDisplay)
        {
            // avisa o useState de mudança
            estadoDoDisplay = false;
            return true;
        }
        return false;
    }
    static void mudarEstadoDoDisplay()
    {
        estadoDoDisplay = true;
    }

    static void LerTeclado()
    {
        // Leitura dos botoes
        BtnFuncao4.read();

        // Açao botao F4
        if (BtnFuncao4.wasPressed())
        {
            mudarEstadoDoDisplay();
            pageMenu = Home;
        }
    }

public:
    static void Print()
    {

        if (obterEstadoDoDisplay())
        {
            tela = 1;
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(0, 1);
            Display::lcd.print("Mon");
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("F4:Home");
        }

        if (EstadoAnt != EstadoSeg)
        {
            Vlr = String(BaseDeTempoSeg); // BaseDeTempoSeg);
            Msg = Vlr + " L/dia";
            Display::lcd.setCursor(0, 0);
            Display::lcd.print(Msg);
            EstadoAnt = EstadoSeg;
        }

        LerTeclado();
    }
};