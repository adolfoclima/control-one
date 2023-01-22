#ifndef BUZZERPAS_H_INCLUDED
#define BUZZERPAS_H_INCLUDED

#include <Arduino.h>

class BuzzerPas
{
private:
    uint8_t m_pin; // arduino pin number connected to button
    bool m_state;

public:
    BuzzerPas(uint8_t pin, bool status = false) : m_pin(pin), m_state(status) {}

    void begin();
    bool getStatus();
    void on();
    void off();
};

#endif
