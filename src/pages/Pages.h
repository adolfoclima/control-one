#pragma once
#include <pages/components/Splash.h>
#include <pages/components/home/Home.h>
#include <pages/components/Sobre.h>
#include <pages/components/Automatico.h>
#include <pages/components/Exemplo.h>
#include <pages/components/Monitor.h>
#include <pages/components/Jardim.h>
#include <pages/components/Tempos.h>
#include <pages/components/Jardim.h>
//#include <pages/components/Bip.h>
#include <pages/components/Ajustes.h>
#include <pages/components/AjustesHora.h>
#include <pages/components/AjustesJardim.h>
#include <pages/components/Alarmes.h>
#include <pages/components/Sensores.h>
#include <pages/components/Pressao.h>

class Pages
{
public:
    static Page_Splash Splash;
    static Page_Home Home;
    static Page_Sobre Sobre;
    static Page_Automatico Automatico;
    static Page_Exemplo Exemplo;
    static Page_Monitor Monitor;
    static Page_Jardim Jardim;
    static Page_Tempos Tempos;
    //static Page_Bip Bip;
    static Page_Ajustes Ajustes;
    static Page_AjustesHora AjustesHora;
    static Page_AjustesJardim AjustesJardim;
    static Page_Alarmes Alarmes;
    static Page_Sensores Sensores;
    static Page_Pressao Pressao;
};