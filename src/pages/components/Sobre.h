#pragma once
#include <config.h>

class Page_Sobre
{
public:
    static void Print()
    {
        Display::lcd.clear();
        Display::lcd.print("LCD Sobre");
        delay(1000);
    }
};