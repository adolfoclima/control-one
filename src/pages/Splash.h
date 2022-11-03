#pragma once
#include <config.h>

class Splash
{
public:
    static void Print()
    {
        LiquidCrystal_I2C lcd = Tela::Instance().lcd;

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Brasil...");
        lcd.setCursor(0, 1);
        lcd.print("acima de tudo,");
        delay(2000);
    }
};