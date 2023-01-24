#ifndef BUZZERPAS_H_INCLUDED
#define BUZZERPAS_H_INCLUDED

#include <Arduino.h>

class BuzzerPas
{
private:
    unsigned int ColetaTempoBuzzer;
    uint8_t m_pin; // arduino pin number connected to button
    bool m_state;
    bool EstadoBuzzer;

    void ContadorBuzzer()
    {
        if (EstadoBuzzer==0)
        {
            ColetaTempoBuzzer = milles();
            EstadoBuzzer=1;
        }
    }

public:
    BuzzerPas(uint8_t pin, bool status = false) : m_pin(pin), m_state(status) {}

    void begin();
    // bool getStatus();
    void bip_dois();
    void bip_tres();
    void bip_um();
};

#endif
