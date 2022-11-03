#pragma once
#include <config.h>

class Sobre
{
private:
    static void Time()
    {
        LiquidCrystal_I2C lcd = Tela::Instance().lcd;
        lcd.clear();
        lcd.print("LCD Time");
        delay(1000);
    }

public:
    static void Print()
    {
        LiquidCrystal_I2C lcd = Tela::Instance().lcd;

        lcd.clear();
        lcd.print("LCD Sobre");        
        delay(1000);
        Time();
    }
};