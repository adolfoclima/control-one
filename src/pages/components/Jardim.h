#pragma once
#include <config.h>

class Page_Jardim
{
private:
    static void Temporizar10min()
    {
        if (EstadoSeg != EstadoAnt)
        {
            EstadoAnt = EstadoSeg;
            tempoJardim++;
        }
    }

    static void AtualizaTela()
    {
        // LiquidCrystal_I2C lcd = Display::Instance().lcd;
        if (tempoJardimAnt != tempoJardim)
        {
            tempoJardimAnt = tempoJardim;
            Display::lcd.setCursor(0, 0);
            Msg = String((15 - tempoJardim)) + "s para fim   ";
            Display::lcd.print(Msg);
        }
    }

    static void PrintFinal()
    {
        Display::lcd.setCursor(0, 0);
        Msg = "Concluido tempo";
        //Display::lcd.print(Msg);
        if ((digitalRead(PIN_BOMBA_CONTATOR)) == LOW)
        {
            digitalWrite(PIN_BOMBA_CONTATOR, HIGH);
        }
        else
        {
            digitalWrite(PIN_BOMBA_CONTATOR, LOW);
        }
    }

    static void LigaBombaTemporizada()
    {

        if (tempoJardimAnt >= 15)
        {
            tempoJardimAnt = 0;
            tempoJardim = 0;
            Funcao = "Desl";
            PrintFinal();
        }
        else
        {
            digitalWrite(PIN_BOMBA_CONTATOR, HIGH);
        }
    }

public:
    static void Print()
    {
        if (tela == 0)
        {
            vlr = milles() / 1000;
            Vlr = String(vlr);
            Vlr = Vlr + " L/dia";
            tela = 1;
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(0, 1);
            Display::lcd.print(Funcao);
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("F4:Home");
            TelaAtual = "JDM";
        }
        Temporizar10min();
        LigaBombaTemporizada();
        AtualizaTela();
    }
};