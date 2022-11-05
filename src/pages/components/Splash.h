#pragma once
#include <config.h>

class Page_Splash
{
public:
    static void Print()
    {
        Display::lcd.clear();
        Display::lcd.setCursor(0, 0);
        Display::lcd.print("Deus...");
        Display::lcd.setCursor(0, 1);
        Display::lcd.print("acima de tudo.");
        delay(2000);
    }
};