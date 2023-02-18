#include "Contator.h"

void Contator::begin()
{
    pinMode(m_pin, OUTPUT);
    if (getStatus())
    {
        on();
    }
}

bool Contator::getStatus()
{
    return m_state;
}

void Contator::on()
{
    m_state = true;
    digitalWrite(m_pin, LOW);
}

void Contator::off()
{
    m_state = false;
    digitalWrite(m_pin,HIGH);
}