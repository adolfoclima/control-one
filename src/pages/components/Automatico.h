#pragma once
#include <config.h>

class Page_Automatico
{
public:
    static void Print()
    {
        Display::lcd.clear();
        Display::lcd.print("LCD Automatico");
        delay(1000);
    }
};