#pragma once
#include <config.h>

class Page_AjustesJardim
{
private:
    static bool obterEstadoDoDisplay()
    {
        if (estadoDoDisplay)
        {
            estadoDoDisplay = false;
            return true;
        }
        return false;
    }

    static void mudarEstadoDoDisplay()
    {
        estadoDoDisplay = true;
    }

    static void Acao1()
    {
        mudarEstadoDoDisplay();
        pageMenu = Home;
    }
    static void Acao2()
    {
        TempoTotalJardim = TempoTotalJardim - 60;
        if (TempoTotalJardim < 60)
        {
            TempoTotalJardim = 1200;
        }
        mudarEstadoDoDisplay();
    }
    static void Acao3()
    {
        TempoTotalJardim = TempoTotalJardim + 60;
        if (TempoTotalJardim > 1200)
        {
            TempoTotalJardim = 60;
        }
        mudarEstadoDoDisplay();
    }

    static void Acao4()
    {
        mudarEstadoDoDisplay();
        pageMenu = Home;
    }

    static void LerTeclado()
    {
        // Leitura dos botoes
        BtnFuncao1.read();
        BtnFuncao2.read();
        BtnFuncao3.read();
        BtnFuncao4.read();
        // Chama ações dos botões
        if (BtnFuncao1.wasPressed())
        {
            Acao1();
        }
        // Açao botao F2
        if (BtnFuncao2.wasPressed())
        {
            Acao2();
        }
        // Açao botao F3
        if (BtnFuncao3.wasPressed())
        {
            Acao3();
        }
        // Açao botao F4
        if (BtnFuncao4.wasPressed())
        {
            Acao4();
        }
    }

public:
    static void Print()
    {
        if (obterEstadoDoDisplay())
        {
            // Atualiza display
            Msg = "Tmp jardim " + String(TempoTotalJardim);
            Display::lcd.clear();
            Display::lcd.setCursor(0, 0);
            Display::lcd.print(Msg);
            Display::lcd.setCursor(0, 1);
            Display::lcd.print(" sai  <  >  ent");
        }
        LerTeclado();
    }
};
