#pragma once
#include <config.h>

class Page_Exemplo
{
private:
    static void Exemplo1()
    {
        // Essa é a opção que já está sendo usada no print()
        Display::Instance(); // Inicialize o display instanciando antes do primeiro uso. Recomendado adicionar essa linha apenas uma vez no setup.
        Display::lcd.clear();
        Display::lcd.print("Exemplo Recomendado!");
        delay(1000);
    }

    static void Exemplo2()
    {
        // Crie uma variavel local e use dentro de sua função. (É mais pesado!)
        LiquidCrystal_I2C lcd = Display::Instance().lcd;
        lcd.clear();
        lcd.print("Exemplo 2");
        delay(1000);
    }

public:
    static void Print()
    {
        Display::lcd.clear();
        Display::lcd.print("LCD Exemplo");
        delay(1000);
        // Exemplo1();
        // Exemplo2();
    }
};