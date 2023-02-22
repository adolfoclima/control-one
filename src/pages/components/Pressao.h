#pragma once
#include <config.h>

class Page_Pressao
{
private:
    static bool obterEstadoDoDisplay()
    {
        if (estadoDoDisplay)
        {
            // avisa o useState de mudança
            estadoDoDisplay = false;
            return true;
        }
        return false;
    }

    static void mudarEstadoDoDisplay()
    {
        estadoDoDisplay = true;
    }

    static void SensorDePressao()
    {
        if (BloqueioDoPressurizador) // Foi bloqueado porque ficou mais de 1 minuto ligado?
        {
            if (FrequenciaPressurizador > 2) // A vazão ainda está alta? (Ou seja, nao desligaram a água?)
            {
                TempoPausaPressao = 0; // Zera o contador do tempo da pausa
            }
            if (TempoPausaPressao > 5) // A vazão está parada a mais de 5 meios segundos?
            {
                if (BloqueioDoPressurizador != 2)
                {                                // Se estiver bloqueado por '1', religa pressurizador, se '2' aguarda reset na tela de alarme
                    BloqueioDoPressurizador = 0; // Libera o pressurizador para voltar a funcionar
                    TempoPressurizador = 0;      // Zera o tempo do pressurizador.
                }
            }
        }
        else // Não está bloequeado...
        {
            if (SensorPressaoPulmao.getStatus()) // Pressostato está acionado?
            {
                if (BloqueioDoPressurizador != 2)
                {                       // Se estiver bloqueado por '1', religa pressurizador, se '2' aguarda reset na tela de alarme
                    Pressurizador.on(); // Liga o Pressurizador
                }
            }
        }
    }

    static void MonitoraPressao()
    {
        if (Pressurizador.getStatus()) // Pressurizador esta acionado?
        {
            if (TempoPressurizador > 2) // Está ligado a mais de 2 meio segundo?
            {
                if (FrequenciaPressurizador < FrequenciaMinimaPressao) // A vazão está abaixo da minima?
                {
                    TempoPressurizador = 0;              // Zera o tempo do pressurizador
                    Pressurizador.off();                 // Desliga pressurizador
                    if (SensorPressaoPulmao.getStatus()) // Pressostato ainda está acionado?
                  
                    {
                        BloqueioDoPressurizador = 2; // Bloqueia o pressurizador por está ligado sem vazao
                        TempoPressurizador = 0;      // Zera o tempo do pressurizador
                        Alarme = 4;                  // Define alarme como 'Falta pressão' (4)
                        mudarEstadoDoDisplay();
                        pageMenu = Alarmes; // Chama tela de alarme
                    }
                }

                if (TempoPressurizador > 30) // O pressurizador está ligado a mais que 120 meios segundos? (1 minuto)
                {
                    Pressurizador.off();         // Desliga pressurizador
                    BloqueioDoPressurizador = 1; // Bloqueia o pressurizador pois está ligado a muito tempo...
                                                 // ...Precisa parar a vazao por 3 segundos para reativar pressão (Vide lógica 'SensoDePressao')
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