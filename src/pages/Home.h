#pragma once
#include <config.h>

class Home
{
public:
    static void Print()
    {
        // Tela::Instance().lcd.print("LCD Home");
        LiquidCrystal_I2C lcd = Tela::Instance().lcd;

        lcd.clear();
        lcd.print("LCD Home");
        delay(1000);
    }
};