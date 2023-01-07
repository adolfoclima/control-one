#pragma once
#include <config.h>

class Page_Pressao
{
private:
    static void SensorDePressao()
    {
        if (SensorPressaoPulmao.getStatus())
        {
            Pressurizador.on();
        }
    }

    static void MonitoraPressao()
    {

        if (Pressurizador.getStatus()) // Pressurizador esta acionado?
        {
            if (TempoPressurizador > 2)
            {
                if (FrequenciaPressurizador < 2)
                {
                    Pressurizador.off(); // Desliga pressurizador
                    TempoPressurizador=0;
                }
            }
        }
    }

public:
    static void Controle()
    {
        SensorDePressao();
        MonitoraPressao();
    }
};