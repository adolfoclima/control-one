#include "Sensor.h"

void Sensor::begin()
{
    pinMode(m_pin, INPUT);
}

bool Sensor::getStatus()
{
    return digitalRead(m_pin);
}

int Sensor::getStatusAnalogic()
{
    return digitalRead(m_pin);
}