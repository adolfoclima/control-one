#pragma once
#include <config.h>

class Page_AjustesHora
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

    static void Acao1()
    {
        mudarEstadoDoDisplay();
        pageMenu = Home;
    }
    static void Acao2()
    {
        if (TipoAjuste == 2)
        {
            HoraAtual--;
            if (HoraAtual < 0)
            {
                HoraAtual = 23;
            }
        }
        else
        {
            MinAtual--;
            if (MinAtual < 0)
            {
                MinAtual = 59;
            }
        }
        mudarEstadoDoDisplay();
    }
    static void Acao3()
    {
        if (TipoAjuste == 2)
        {
            HoraAtual++;
            if (HoraAtual > 23)
            {
                HoraAtual = 0;
            }
        }
        else
        {
            MinAtual++;
            if (MinAtual > 59)
            {
                MinAtual = 0;
            }
        }
        mudarEstadoDoDisplay();
    }
    static void Acao4()
    {
        !TipoAjuste == 2
            ? TipoAjuste = 3
            : TipoAjuste = 2;
        mudarEstadoDoDisplay();
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
            // Formatação dos horários
            if (HoraAtual < 10)
            {
                SHoraAtual = "0" + String(HoraAtual);
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
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(0, 0);
            if (TipoAjuste == 2)
            {
                Msg = "Ajst Hora  " + SHoraAtual + ":" + SMinAtual;
            }
            else
            {
                Msg = "Ajst Min   " + SHoraAtual + ":" + SMinAtual;
            }
            Display::lcd.print(Msg);
            Display::lcd.setCursor(0, 1);
            if (TipoAjuste == 2)
            {
                Display::lcd.print(" sai  <  >  Min");
            }
            else
            {
                Display::lcd.print(" sai  <  >  Hora");
            }
        }
        LerTeclado();
    }
};