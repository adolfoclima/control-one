#pragma once
#include <config.h>

class Automatico
{
public:
    static void Print()
    {
        LiquidCrystal_I2C lcd = Tela::Instance().lcd;

        lcd.clear();
        lcd.print("LCD Automatico");
        delay(1000);
    }
};