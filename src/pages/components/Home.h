#pragma once
#include <config.h>

class Page_Home
{
public:
    static void Print()
    {
        Display::lcd.clear();
        Display::lcd.setCursor(1, 0);
        Display::lcd.print("F1:Mon");
        Display::lcd.setCursor(9, 0);
        Display::lcd.print("F2:Aut");
        Display::lcd.setCursor(1, 1);
        Display::lcd.print("F3:Jdm");
        Display::lcd.setCursor(9, 1);
        Display::lcd.print("F4:Dsl");
        tela = 0;
    }
};