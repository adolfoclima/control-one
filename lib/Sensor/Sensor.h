#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

#include <Arduino.h>

class Sensor
{
private:
    uint8_t m_pin; // Numero do pino no ESP

public:
    Sensor(uint8_t pin) : m_pin(pin) {}

    void begin();
    bool getStatus();
    int getStatusAnalogic();
};

#endif