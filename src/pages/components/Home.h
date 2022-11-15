#pragma once
#include <config.h>

class Page_Home
{
public:
    static void Print()
    {
        if (tela == 0)
        {
            tela = 1;
            // Atualiza display
            Display::lcd.clear();
            Display::lcd.setCursor(1, 0);
            Display::lcd.print("F1:Mon");
            Display::lcd.setCursor(9, 0);
            Display::lcd.print("F2:Aut");
            Display::lcd.setCursor(1, 1);
            Display::lcd.print("F3:Jdm");
            Display::lcd.setCursor(9, 1);
            Display::lcd.print("F4:Dsl");
            // Marcador de funcao
            if (Funcao == "Mon")
            {
                Display::lcd.setCursor(0, 0);
            }
            if (Funcao == "Auto")
            {
                Display::lcd.setCursor(8, 0);
            }
            if (Funcao == "Jdm")
            {
                Display::lcd.setCursor(0, 1);
            }
            if (Funcao == "Desl")
            {
                Display::lcd.setCursor(8, 1);
            }
            Display::lcd.print(">");
            delay(1000);
        }
    }
};