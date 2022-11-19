#pragma once
#include <config.h>

class Page_Home
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

    static void ParaTudo()
    {
        // Desliga contator da bomba
        Bomba.off();
    }

    static void HUD()
    {
        if (obterEstadoDoDisplay())
        {
            Display::lcd.clear();
            Display::lcd.setCursor(1, 0);
            Display::lcd.print("1:Mon");
            Display::lcd.setCursor(1, 1);
            Display::lcd.print("2:Aut");
            Display::lcd.setCursor(9, 0);
            Display::lcd.print("3:Jdm");
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("4:Ajt");
        }
    }

    static void LerTeclado()
    {
        // Leitura dos botoes
        BtnFuncao1.read();
        BtnFuncao2.read();
        BtnFuncao3.read();

        //  Açao botao F1
        if (BtnFuncao1.wasPressed())
        {
            mudarEstadoDoDisplay();
            pageMenu = Monitor;
        }

        // Açao botao F2
        if (BtnFuncao2.wasPressed())
        {
            mudarEstadoDoDisplay();
            pageMenu = Automatico;
        }

        // Açao botao F3
        if (BtnFuncao3.wasPressed())
        {
            mudarEstadoDoDisplay();
            pageMenu = Jardim;
        }
    }

public:
    static void Print()
    {
        ParaTudo();
        HUD();
        LerTeclado();
    }
};