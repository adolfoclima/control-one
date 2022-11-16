#pragma once
#include <config.h>

class Page_Controle
{
private:
    static void ControleDeNivel()
    {
        // Ação Sensores de niveis
        !SensorNivelSuperior.getStatus()
        ? Bomba.off()
        : SensorNivelInferior.getStatus()
        ? Bomba.on()
        : void();
    }

public:
    static void Nivel()
    {
        ControleDeNivel();
    }
};