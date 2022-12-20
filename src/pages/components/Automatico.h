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

    //............................... Le teclado
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
                TempoBomba = 0;
                mudarEstadoDoDisplay(); // Habilita atualizacao do display
                pageMenu = Home;        // Chama página Home
            }
            else
            {
                TempoBackLigth = 1;
            }
        }
    }
    //............................... Controle de nível
    static void ControleDeNivel()
    {
        if (Alarme == 0)
        {
            !SensorNivelSuperior.getStatus()      // Nivel superior NAO está acionado?
                ? Bomba.off()                     // Desliga bomba
                : SensorNivelInferior.getStatus() // Nivel inferior acionado?
                      ? Bomba.on()                // Liga bomba
                      : void();                   // faz nada
        }

        if (!SensorNivelInferior.getStatus()) // Nível inferior acionado habilitado o nível crítico
        {
            HabilitaNivelCritico = 1; // Nível crítico esta habilitado
        }

        if (HabilitaNivelCritico) // Nível crítico esta habilitado?
        {
            if (SensorNivelCritico.getStatus()) // Nível critico esta acionado?
            {
                Bomba.off();            // Desliga bomba
                Alarme = 2;             // Informa o id do alarme
                mudarEstadoDoDisplay(); // Habilita atualizacao do display
                pageMenu = Alarmes;     // Chama a página de alarmes
            }
        }
    }

    static void MonitoraVazao()
    {

        if (Bomba.getStatus()) // Nível critico esta acionado?
        {
            if (TempoBomba > 10)
            {
                if (FrequenciaBomba < 2)
                {
                    Bomba.off();            // Desliga bomba
                    Alarme = 3;             // Informa o id do alarme
                    mudarEstadoDoDisplay(); // Habilita atualizacao do display
                    pageMenu = Alarmes;     // Chama a página de alarmes
                }
            }
        }
    }

    static void LigarDisplayTemporariamente()
    {
        if (Bomba.getStatus() == !StatusBombaAnterior)
        {
            TempoBackLigth = 1;
            StatusBombaAnterior = Bomba.getStatus();
        }
    }

public:
    static void Print()
    {
        if (obterEstadoDoDisplay())
        {
            TempoBackLigth = 1;
            // Atualiza display
            Display::lcd.clear();
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
                    TempoBomba = 0;
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

        LigarDisplayTemporariamente();
        ControleDeNivel();
        MonitoraVazao();
        LerTeclado();
    }
};