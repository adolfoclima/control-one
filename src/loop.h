#ifndef LOOP_H_INCLUDED
#define LOOP_H_INCLUDED

#include <config.h>
#include <pages/Pages.h>

void Alarmes()
{
    Pages::Bip.Print();
}

// Tela de monitoramento
void Leitura()
{
    // Seleção de telas
    if (TelaAtual == "MON")
    {
        Pages::Monitor.Print(); // Chama tela
    }
    if (Funcao == "JDM")
    {
        Pages::Jardim.Print();
    }
    if (Funcao == "HOME")
    {
        Pages::Home.Print();
    }
}

// Leitura e comandos dos butoes

// Comandos (Lógica em varredura)

void Temporizadores()
{
    // Chamada de Temporizadores
    Pages::Tempos.Print();
}

/////////////////////LOOP///////////////////////////
void loop()
{
    // Botoes();         // Leitura de botoes
    //                   // Execução do comando definido pelo botao
    Temporizadores(); // Execução de temporizadores
    // Alarmes();
    // Leitura();

    switch (pageMenu)
    {
    case Home:
        Pages::Home.Print();
        break;
    case Monitor:
        Pages::Monitor.Print(); // Chama tela
        break;
    case Automatico:
        Pages::Automatico.Print(); // Chama tela
        break;
    case Jardim:
        Pages::Jardim.Print(); // Chama tela
        break;
    default:
        Pages::Home.Print();
        break;
    }
}

#endif