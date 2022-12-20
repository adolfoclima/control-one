#ifndef LOOP_H_INCLUDED
#define LOOP_H_INCLUDED

#include <config.h>
#include <pages/Pages.h>

void Temporizadores()
{
    // Chamada de Temporizadores
    Pages::Tempos.Print();
}

void ContadorDaVazoes()
{
    Pages::Vazoes.Registro();
}

//////////////S=///////LOOP///////////////////////////
void loop()
{
    // Botoes();         // Leitura de botoes
    //                   // Execução do comando definido pelo botao
    Temporizadores(); // Execução de temporizadores
    // Alarmes();
    // Leitura();
    ContadorDaVazoes();

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
    case Ajustes:
        Pages::Ajustes.Print(); // Chama tela
        break;
    case AjustesHora:
        Pages::AjustesHora.Print(); // Chama tela
        break;
    case AjustesJardim:
        Pages::AjustesJardim.Print(); // Chama tela
        break;
    case Alarmes:
        Pages::Alarmes.Print(); // Chama tela
        break;                  // AjustesJardim
    default:
        Pages::Home.Print();
        break;
    }
}

#endif