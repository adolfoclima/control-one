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

    static void HUD()
    {
        if (obterEstadoDoDisplay())
        {
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(1, 0);
            Display::lcd.print("F1:Mon");
            Display::lcd.setCursor(9, 0);
            Display::lcd.print("F2:Aut");
            Display::lcd.setCursor(1, 1);
            Display::lcd.print("F3:Jdm");
            Display::lcd.setCursor(8, 1);
            Display::lcd.print(">F4:Dsl");
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
        HUD();
        LerTeclado();
    }
};