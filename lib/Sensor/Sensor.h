#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

#include <Arduino.h>

class Sensor
{

private:
    uint8_t m_pin; // arduino pin number connected to button

public:
    Sensor(uint8_t pin) : m_pin(pin) {}

    void begin();
    bool getStatus();
    int getStatusAnalogic();
};

#endif