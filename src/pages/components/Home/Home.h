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
            Display::lcd.print("4:Ajst");
            TempoBackLigth = 1;
        }
    }

    static void LerTeclado()
    {
        // Leitura dos botoes
        BtnFuncao1.read();
        BtnFuncao2.read();
        BtnFuncao3.read();
        BtnFuncao4.read();

        //  Açao botao F1
        if (BtnFuncao1.wasPressed())
        {
            if (TempoBackLigth)
            {
                mudarEstadoDoDisplay();
                pageMenu = Monitor;
            }
            else
            {
                TempoBackLigth = 1;
            }
        }

        // Açao botao F2
        if (BtnFuncao2.wasPressed())
        {
            Alarme = 0;
            TempoBomba = 0;
            if (TempoBackLigth)
            {
                mudarEstadoDoDisplay();
                pageMenu = Automatico;
            }
            else
            {
                TempoBackLigth = 1;
            }
        }

        // Açao botao F3
        if (BtnFuncao3.wasPressed())
        {
            if (TempoBackLigth)
            {
                mudarEstadoDoDisplay();
                pageMenu = Jardim;
            }
            else
            {
                TempoBackLigth = 1;
            }
        }

        // Açao botao F4
        if (BtnFuncao4.wasPressed())
        {
            if (TempoBackLigth)
            {
                mudarEstadoDoDisplay();
                pageMenu = Ajustes;
            }
            else
            {
                TempoBackLigth = 1;
            }
        }
    }

    static void SaiDoHome()
    {
        if (TempoBackLigth > 15)
        {
            mudarEstadoDoDisplay();
            pageMenu = Monitor;
        }
    }

public:
    static void Print()
    {
        ParaTudo();
        HUD();
        LerTeclado();
        SaiDoHome();
    }
};