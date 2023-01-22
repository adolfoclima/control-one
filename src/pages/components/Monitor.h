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
        BtnFuncao1.read();
        BtnFuncao2.read();
        BtnFuncao3.read();
        BtnFuncao4.read();

        if (BtnFuncao1.wasPressed())
        {
            TempoBackLigth = 1;
        }
        if (BtnFuncao2.wasPressed())
        {
            TempoBackLigth = 1;
        }
        if (BtnFuncao3.wasPressed())
        {
            TempoBackLigth = 1;
        }
        // Açao botao F4
        if (BtnFuncao4.wasPressed())
        {
            if (TempoBackLigth)
            {
                mudarEstadoDoDisplay();
                pageMenu = Home;
            }
            else
            {
                TempoBackLigth = 1;
            }
        }
    }

public:
    static void Print()
    {
        if (obterEstadoDoDisplay())
        {
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(0, 1);
            Display::lcd.print("Deslig");
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("4:Home");
        }

        if (EstadoAnt != EstadoSeg)
        {
            Vlr = String(VazaoTotalPressurizador); // BaseDeTempoSeg);
            Msg = Vlr + " L";
            Display::lcd.setCursor(0, 0);
            Display::lcd.print(Msg);
            Display::lcd.setCursor(11, 0);
            Display::lcd.print(SHoraAtual);
            if (TempoBackLigth > 10)
            {
                Display::lcd.noBacklight();
            }
            EstadoAnt = EstadoSeg;
        }

        LerTeclado();
    }
};