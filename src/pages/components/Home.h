#pragma once
#include <config.h>

class Page_Home
{
public:
    static void Print()
    {
        Display::lcd.clear();
        Display::lcd.print("LCD Home");
        delay(1000);
    }
};