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
    unsigned long previousMillis = 0;
    unsigned int IncrementoIntervalo; // Contador do tempo do bip
    const int interval = 200;        // intervalo de 5 segundos em milissegundos
    const int blinkInterval = 250;    // intervalo de piscada em milissegundos
    int blinkCount = 0;               // contador de piscadas
    int state = LOW;
    int count = 0;

public:
    BuzzerPas(uint8_t pin, bool status = false) : m_pin(pin), m_state(status) {}

    void begin();
    // bool getStatus();
    void bip_um();
    void bip_dois();
    void bip_tres();
};

#endif
