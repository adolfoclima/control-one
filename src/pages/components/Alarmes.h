#pragma once
#include <config.h>
#include <Bips.h>

class Page_Alarmes
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
            BloqueioDoPressurizador = 0; // Libera o pressurizador para voltar a funcionar
            TempoBackLigth = 1;
            Alarme = 0;
            TempoAlarme = 0;
            mudarEstadoDoDisplay();
            pageMenu = Home;
            Buzzer.bip_zero();
        }
    }

    static void IniciaTempoBuzzer()
    {
        switch (Alarme)
        {
        case 1:
            EstadoBuzzer = 0;
            Buzzer.bip_um();
            break;
        case 2:
            EstadoBuzzer = 0;
            Buzzer.bip_dois();
            break;
        case 3:
            EstadoBuzzer = 0;
            Buzzer.bip_tres();
            break;
        case 4:
            EstadoBuzzer = 0;
            Buzzer.bip_tres();
            break;
        default:
            break;
        }
    }

public:
    static void Print()
    {
        if (obterEstadoDoDisplay())
        {
            TempoBackLigth = 401; // 0= Display apagado, 1= Display aceso, 401= Display piscando (ALERTA)
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(0, 1);
            Display::lcd.print("ALARME");
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("4:Rst");
            switch (Alarme)
            {
            case 0:
                Msg = "Sem erro";
                break;
            case 1:
                Msg = "Tempo limite";
                break;
            case 2:
                HabilitaNivelCritico = 0;
                Msg = "Nivel critico";
                break;
            case 3:
                Msg = "Falta fluxo";
                break;
            case 4:
                Msg = "Falta pressao";
                break;
            default:
                break;
            }
            Display::lcd.setCursor(0, 0);
            Display::lcd.print(Msg);
        }
        LerTeclado();
        IniciaTempoBuzzer();
    }
};