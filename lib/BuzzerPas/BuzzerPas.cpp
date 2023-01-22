
#include "BuzzerPas.h"

void BuzzerPas::begin()
{
    pinMode(m_pin, OUTPUT);
    if (getStatus())
    {
        on();
    }
}

bool BuzzerPas::getStatus()
{
    return m_state;
}

void BuzzerPas::on()
{
    m_state = true;
    digitalWrite(m_pin, HIGH);
}

void BuzzerPas::off()
{
    m_state = false;
    digitalWrite(m_pin, LOW);
}