#pragma once
#include <config.h>

class Page_Sensores
{
private:
    static void VazaoBomba()
    {
        if (SensorFluxoBomba.getStatus())
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
    }

    static void VazaoPressurizador()
    {
        if (SensorFluxoPressurizador.getStatus())
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
    }

    static void ComputarVazoes()
    {
        if (EstadoMeioSeg != AnteriorMeioSeg)
        {
            AnteriorMeioSeg = EstadoMeioSeg;
            // Vazao e frequencia da boba
            MililitrosBomba = MililitrosBomba + ContadorPulsoBomba;
            FrequenciaBomba = ContadorPulsoBomba;
            ContadorPulsoBomba = 0;
            VazaoTotalBomba = MililitrosBomba * CalibracaoFatorBomba;

            // Vazao e frequencia do pressurizador
            MililitrosPressurizador = MililitrosPressurizador + ContadorPulsoPressurizador;
            FrequenciaPressurizador = ContadorPulsoPressurizador;
            ContadorPulsoPressurizador = 0;
            VazaoTotalPressurizador = MililitrosPressurizador * CalibracaoFatorPressurizador;
        }
    }

public:
    static void Registro()
    {
        VazaoBomba();
        VazaoPressurizador();
        ComputarVazoes();
    }
};