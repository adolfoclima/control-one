
#include "BuzzerPas.h"

void BuzzerPas::begin()
{
    pinMode(m_pin, OUTPUT);
}

void BuzzerPas::bip_um()
{
    ContadorBuzzer();
    if (milles() - ColetaTempoBuzzer > 5000)        // Reinicio do ciclo
    {
        digitalWrite(m_pin, HIGH);
        ColetaTempoBuzzer = milles();
    }    
    else if (milles() - ColetaTempoBuzzer > 200)    // Fim do bip 1
    {
        digitalWrite(m_pin, LOW);
    }
    else if (milles() - ColetaTempoBuzzer > 0)      // Inicio do bip 1
    {
        digitalWrite(m_pin, HIGH);
    }
}

void BuzzerPas::bip_dois()
{
    ContadorBuzzer();
    if (milles() - ColetaTempoBuzzer > 5000)        // Reinicio do ciclo
    {
        digitalWrite(m_pin, HIGH);
        ColetaTempoBuzzer = milles();
    }    
    else if (milles() - ColetaTempoBuzzer > 500)    // Fim do bip 2
    {
        digitalWrite(m_pin, LOW);
    }
    else if (milles() - ColetaTempoBuzzer > 300)      // Inicio do bip 2
    {
        digitalWrite(m_pin, HIGH);
    }
        else if (milles() - ColetaTempoBuzzer > 200)    // Fim do bip 1
    {
        digitalWrite(m_pin, LOW);
    }
    else if (milles() - ColetaTempoBuzzer > 0)      // Inicio do bip 1
    {
        digitalWrite(m_pin, HIGH);
    }
}

void BuzzerPas::bip_tres()
{
    digitalWrite(m_pin, LOW);
}
