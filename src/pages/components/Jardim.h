#pragma once
#include <config.h>

class Page_Jardim
{
private:
    static void ControleTempo()
    {
        if (tempoJardim > 0)
        {
            Bomba.on();
            tempoJardim--;
        }
        else
        {
            Bomba.off();
        }
    }

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
        if (BtnFuncao4.wasPressed()) // Botão acionado?
        {
            if (TempoBackLigth)
            {
                mudarEstadoDoDisplay(); // Habilita atualizacao do display
                pageMenu = Home;        // Chama página Home
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
            Display::lcd.print("Jardim");
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("4:Home");
            tempoJardim = 600;
        }

        if (EstadoAnt != EstadoSeg)
        {
            // tempoJardimAnt = tempoJardim;
            if (tempoJardim)
            {
                Msg = String(tempoJardim) + "s para fim...    ";
            }
            else
            {
                Msg = "tempo concluido ";
                TempoBackLigth=401;
            }
            Display::lcd.setCursor(0, 0);
            Display::lcd.print(Msg);
            ControleTempo();
            EstadoAnt = EstadoSeg;
        }

        LerTeclado();
    }
};