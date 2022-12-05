#pragma once
#include <config.h>

class Page_Automatico
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

    static void ControleDeNivel()
    {
        if (Alarme == 0)
        {
            !SensorNivelSuperior.getStatus()
                ? Bomba.off()
            : SensorNivelInferior.getStatus()
                ? Bomba.on()
                : void();
        }
    }

public:
    static void Print()
    {
        if (obterEstadoDoDisplay())
        {
            // Atualiza display
            Display::lcd.clear();
            //

            //
            Display::lcd.setCursor(0, 1);
            Display::lcd.print("Auto");
            Display::lcd.setCursor(10, 1);
            Display::lcd.print("4:Home");
        }

        if (EstadoAnt != EstadoSeg)
        {
            Vlr = String(BaseDeTempoSeg); // BaseDeTempoSeg);
            Msg = Vlr + " L/dia";
            Display::lcd.setCursor(0, 0);
            Display::lcd.print(Msg);
            // Formatação dos horários
            if (Bomba.getStatus())
            {
                TempoBomba++;
                if (TempoBomba > 360) // A L A R M E S 
                {
                    Bomba.off();
                    Alarme = 1;
                    mudarEstadoDoDisplay();
                    pageMenu = Alarmes;
                }
                else if (TempoBomba > 299)
                {
                    PreviatempoBomba = TempoBomba / 60;
                    if (PreviatempoBomba < 10)
                    {
                        STempoBomba = " " + String(PreviatempoBomba) + "m  ";
                    }
                    else if (PreviatempoBomba < 100)
                    {
                        STempoBomba = " " + String(PreviatempoBomba) + "m ";
                    }
                    else
                    {
                        STempoBomba = " " + String(PreviatempoBomba) + "m";
                    }
                }
                else
                {
                    if (PreviatempoBomba < 10)
                    {
                        STempoBomba = " " + String(TempoBomba) + "s  ";
                    }
                    else if (PreviatempoBomba < 100)
                    {
                        STempoBomba = " " + String(TempoBomba) + "s ";
                    }
                    else
                    {
                        STempoBomba = " " + String(TempoBomba) + "s";
                    }
                }
            }
            else
            {
                STempoBomba = "     ";
                TempoBomba = 0;
            }
            Display::lcd.setCursor(4, 1);
            Display::lcd.print(STempoBomba);

            // Msg = SHoraAtual; //+ ":" + SMinAtual
            Display::lcd.setCursor(11, 0);
            Display::lcd.print(SHoraAtual);
            EstadoAnt = EstadoSeg;
        }

        ControleDeNivel();
        LerTeclado();
    }
};