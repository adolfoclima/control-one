
// #include <config.h>
#include "BuzzerPas.h"

void BuzzerPas::begin()
{
    pinMode(m_pin, OUTPUT);
}

void BuzzerPas::bip_um()
{
    unsigned long currentMillis = milles();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        if (count < 1)
        {
            if (state == LOW)
            {
                state = HIGH;
            }
            else
            {
                state = LOW;
                count++;
            }
        }
        else if (count == 1)
        {
            count++;
        }
        else if (count > 1)
        {
            state = LOW;
            count++;
        }
        
        if (count == 12)
        {
            count = 0;
        }

        digitalWrite(m_pin, state);
    }
}

void BuzzerPas::bip_dois()
{
    unsigned long currentMillis = milles();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        if (count < 2)
        {
            if (state == LOW)
            {
                state = HIGH;
            }
            else
            {
                state = LOW;
                count++;
            }
        }
        else if (count == 2)
        {
            count++;
        }
        else if (count > 2)
        {
            state = LOW;
            count++;
        }
        
        if (count == 20)
        {
            count = 0;
        }

        digitalWrite(m_pin, state);
    }
}

void BuzzerPas::bip_tres()
{
    unsigned long currentMillis = milles();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        if (count < 3)
        {
            if (state == LOW)
            {
                state = HIGH;
            }
            else
            {
                state = LOW;
                count++;
            }
        }
        else if (count == 3)
        {
            count++;
        }
        else if (count > 3)
        {
            state = LOW;
            count++;
        }
        
        if (count == 20)
        {
            count = 0;
        }

        digitalWrite(m_pin, state);
    }
}
