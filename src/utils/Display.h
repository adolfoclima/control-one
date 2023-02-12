// UI.h
#pragma once

#include <LiquidCrystal_I2C.h>

class Display
{

public:
    static Display &Instance()
    {
        if (Display::pInstance == nullptr)
            Display::pInstance = new Display();
        return *Display::pInstance;
    }

    static LiquidCrystal_I2C lcd;

    // static void test() { Serial.println("Serial Test"); }
    static void splash()
    {
        lcd.setCursor(0, 0);
        lcd.print("Deus...");
        lcd.setCursor(0, 1);
        lcd.print("acima de todos,");
        delay(500);
        lcd.clear();
    }

private:
    static Display *pInstance; // Variável estática segurando o ponteiro para a única instância deste

    Display()
    {
        lcd.init();
        lcd.backlight();
    }
};