#pragma once
#include <config.h>

class Page_Desliga
{
private:
    static void ParaTudo()
    {
        // Desliga contator da bomba
        digitalWrite(PIN_BOMBA_CONTATOR, LOW);
    }
    

public:
    static void Print()
    {
        ParaTudo();
    }
};