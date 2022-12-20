#pragma once
#include <config.h>

class Page_Vazoes
{
private:
    static void VazaoBomba()
    {
        Pulso = digitalRead(PIN_FLUXO_BOMBA);
        if (Pulso)
        {
            if (PulsoBomba == 0)
            {
                ContadorPulsoBomba++;
                PulsoBomba = 1;
            }
        }
        else
        {
            PulsoBomba = 0;
        }
        // digitalWrite(PIN_LED_DEBUG, HIGH);

        if (EstadoMeioSeg != AnteriorMeioSeg)
        {
            AnteriorMeioSeg = EstadoMeioSeg;
            MililitrosBomba = MililitrosBomba + ContadorPulsoBomba;
            FrequenciaBomba = ContadorPulsoBomba;
            ContadorPulsoBomba = 0;
            VazaoTotalBomba = MililitrosBomba * CalibracaoFatorBomba;
            // VazaoTotalBomba = 3;
        }
    }

    static void VazaoPressurizador()
    {
        Pulso = digitalRead(PIN_FLUXO_PRESSURIZADOR);
        if (PulsoPressurizador)
        {
            if (PulsoPressurizador == 0)
            {
                ContadorPulsoPressurizador++;
                PulsoPressurizador = 1;
            }
        }
        else
        {
            PulsoPressurizador = 0;
        }
        // digitalWrite(PIN_LED_DEBUG, HIGH);

        if (EstadoMeioSeg != AnteriorMeioSeg)
        {
            AnteriorMeioSeg = EstadoMeioSeg;
            MililitrosPressurizador = MililitrosPressurizador + ContadorPulsoPressurizador;
            FrequenciaPressurizador = ContadorPulsoPressurizador;
            ContadorPulsoPressurizador = 0;
            VazaoTotalPressurizador = MililitrosPressurizador * CalibracaoFatorPressurizador;
            // VazaoTotalBomba = 3;
        }
    }

public:
    static void Registro()
    {
        VazaoBomba();
        VazaoPressurizador();
    }
};