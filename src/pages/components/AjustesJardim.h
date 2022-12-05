#pragma once
#include <config.h>

class Page_AjustesJardim
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
        TipoAjuste--;
        if (TipoAjuste < 0)
        {
            TipoAjuste = 3;
        }
        mudarEstadoDoDisplay();
    }
    static void Acao3()
    {
        TipoAjuste++;
        if (TipoAjuste > 3)
        {
            TipoAjuste = 0;
        }
        mudarEstadoDoDisplay();
    }
    static void Acao4()
    {
        switch (TipoAjuste)
        {
        case 0:
            mudarEstadoDoDisplay();
            pageMenu = Home;
            break;
        case 1:
            mudarEstadoDoDisplay();
            pageMenu = Home;
            break;
        case 2:
            mudarEstadoDoDisplay();
            pageMenu = AjustesHora;
            break;
        case 3:
            mudarEstadoDoDisplay();
            pageMenu = AjustesHora;
            break;
        default:
            break;
        }
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
            Display::lcd.clear();
            Display::lcd.setCursor(0, 0);
            switch (TipoAjuste)
            {
            case 0:
                Display::lcd.print("0-Tempo jardim");
                break;
            case 1:
                Display::lcd.print("1-Vazao minima");
                break;
            case 2:
                Display::lcd.print("2-Ajuste Hora");
                break;
            case 3:
                Display::lcd.print("3-Ajuste Minuto");
                break;
            default:
                break;
            }

            Display::lcd.setCursor(0, 1);
            Display::lcd.print(" sai  <  >  ent ");
        }

        /*if (EstadoAnt != EstadoSeg)
        {

            //Msg = String(segundosJardim) + "  ";
            //Display::lcd.setCursor(11, 0);
            //Display::lcd.print(Msg);
            //EstadoAnt = EstadoSeg;
        }*/
        LerTeclado();
    }
};
