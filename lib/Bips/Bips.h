/*

#ifndef _BIPS_H
#define _BIPS_H

#include <config.h>
#include <Arduino.h>

class Bips
{

private:
    uint8_t _pin; // Pin de saída
    uint8_t EstadoBuzzer;
    byte EstadoBuzzer = LOW;

public:
    // Metodo construtor
    Bips(uint8_t pin) : _pin(pin)
    {
        pinMode(_pin, OUTPUT); // Configura a porta como saída
    }

    void one()
    {
        // Verifica se o tempo de alarme é maior que 5
        if (TempoAlarme > 5)
        {
            TempoAlarme = 1; // Configura para 1
        }
        // Verifica se é maior que 2
        else if (TempoAlarme > 2)
        {
            digitalWrite(_pin, LOW); // Desliga o alarme
        }
        // Verifica se é maior que 1
        else if (TempoAlarme > 1)
        {
            digitalWrite(_pin, HIGH); // Liga o alarme
        }
    }

    static void TempoBuzzer()
    {
        BaseDeTempoBuzzer = milles();
        BaseDeTempoBuzzer = BaseDeTempoBuzzer / 200;

        if (BaseDeTempoBuzzer - PreviousBaseDeTempoBuzzer >= 1)
        {
            PreviousBaseDeTempoBuzzer = BaseDeTempoBuzzer;
            // if the LED is off turn it on and vice-versa:
            if (EstadoBuzzer == LOW)
            {
                EstadoBuzzer = HIGH;
                ContadorBuzzer();
            }
            else
            {
                EstadoBuzzer = LOW;
                ContadorBuzzer();
            }
        }
    }

    static void ContadorBuzzer() // Acoes a cada meio segundo
    {
        if (Alarme)
        {
            TempoAlarme++;
        }
    }
};

#endif
*/