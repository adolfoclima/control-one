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
void Botoes()
{
    // Leitura dos botoes
    BtnFuncao1.read();
    BtnFuncao2.read();
    BtnFuncao3.read();
    BtnFuncao4.read();
    //  Açao botao F1
    if (BtnFuncao1.wasPressed()) // if the button was released, change the LED state
    {
        if (TelaAtual == "HOME")
        {
            ManterLeitura = 1;
            tela = 0;
        }
    }
    // Açao botao F2
    if (BtnFuncao2.wasPressed()) // if the button was released, change the LED state
    {
        if (TelaAtual == "HOME")
        {
            tela = 0;
            Funcao = "Auto";
            TelaAtual = "MON";
        }
    }

    // Açao botao F3
    if (BtnFuncao3.wasPressed()) // if the button was released, change the LED state
    {
        if (TelaAtual == "HOME")
        {
            tela = 0;
            Funcao = "Jdm";
        }
    }
    // Açao botao F4
    if (BtnFuncao4.wasPressed()) // if the button was released, change the LED state
    {
        if (TelaAtual == "HOME")
        {
            ManterLeitura = 0;
            tela = 0;
            Funcao = "Desl";
            TelaAtual = "HOME";
        }
        else
        {
            tela = 0;
            TelaAtual = "HOME";
        }
    }
}

// Comandos (Lógica em varredura)
void Comandos()
{
    // Seleção de função
    if (Funcao == "Auto")
    {
        Pages::Controle.Nivel(); // Chama classe de controle
        TelaAtual = "MON";       // Chama tela
        tela = 0;
    }
    if (Funcao == "Jdm")
    {
        Pages::Jardim.Print();
    }
    if (Funcao == "Desl")
    {
        Pages::Desliga.Print();
    }
}
void Temporizadores()
{
    // Chamada de Temporizadores
    Pages::Tempos.Print();
}


/////////////////////LOOP///////////////////////////
void loop()
{
    Botoes();         // Leitura de botoes
    Comandos();       // Execução do comando definido pelo botao
    Temporizadores(); // Execução de temporizadores
    Alarmes();
    Leitura();
    
}

#endif