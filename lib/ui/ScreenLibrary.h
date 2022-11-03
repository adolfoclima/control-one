// UI.h
#pragma once

#include <LiquidCrystal_I2C.h>

class Tela
{

public:
    static Tela &Instance()
    {
        if (Tela::pInstance == nullptr)
            Tela::pInstance = new Tela();
        return *Tela::pInstance;
    }

    static LiquidCrystal_I2C lcd;

    // static void test() { Serial.println("Serial Test"); }
    static void splash()
    {
        lcd.setCursor(0, 0);
        lcd.print("Brasil...");
        lcd.setCursor(0, 1);
        lcd.print("acima de tudo,");
        delay(500);
        lcd.clear();
    }

private:
    static Tela *pInstance; // Static variable holding the pointer to the only instance of this

    Tela()
    {
        lcd.init();
        lcd.backlight();
    }
};