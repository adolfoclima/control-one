#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

/*.....................................................
Dolphin
Cn-One - controle avançado de nível
01 de outubro de 2022
/.....................................................*/

/*--------------------- Includes ---------------------*/
#include <Arduino.h> // Arduino no VScode
#include <Wire.h>    // Arduino no ESP

#include <../lib/Button/Button.h> // https://github.com/JChristensen/JC_Button
#include <../lib/Contator/Contator.h>
#include <../lib/Sensor/Sensor.h>
#include <utils/Display.h>

// Declaração dos pinos do ESP32
const byte PIN_LED_DEBUG(2);

const int PIN_BOMBA_CONTATOR(12);
const int PIN_BOMBA_CORRENTE(A4);
const int PIN_BUZZER(4);

const int PIN_PRESSURIZADOR_CONTATOR(4);
const int PIN_PRESSURIZADOR_CORRENTE(A5);

const byte PIN_BTN_FUNCAO_1(34);
const byte PIN_BTN_FUNCAO_2(35);
const byte PIN_BTN_FUNCAO_3(36);
const byte PIN_BTN_FUNCAO_4(39);

const byte PIN_SENSOR_NIVEL_SUPERIOR(19); // 19, 25
const byte PIN_SENSOR_NIVEL_INFERIOR(18); // 18, 26
const byte PIN_SENSOR_NIVEL_CRITICO(5);   // 5, 27
const byte PIN_FLUXO_BOMBA(14);
const byte PIN_FLUXO_PRESSURIZADOR(13);

// Declaracao de variaveis 'bool'
static bool ledState;
// Declaração de variáveis 'byte'
byte tela;
byte ManterLeitura;
byte FLAG;
byte EstadoSeg;
byte EstadoAnt;
// Declaracao de variaveis 'Int'
int previous1Seg;
int tempoJardim;
int tempoJardimAnt;
int Alarme = 0;

// Declaração de variáveis 'Ultra longa'
long unsigned int vlr;
long unsigned int BaseDeTempoSeg;

// Declaração de variáveis 'String'
String Vlr = "";
String VlrAnt = "";
String Funcao = "Desl";
String TelaAtual = "HOME";
String Msg = "";

enum PagesMenu
{
    Home,
    Monitor,
    Automatico,
    Jardim
};

bool estadoDoDisplay = true;

PagesMenu pageMenu = Home;

// Declaração e Setup do display
Display *Display::pInstance = nullptr;
LiquidCrystal_I2C Display::lcd(0x27, 16, 2);

// Declara os Buttons
Button BtnFuncao1(PIN_BTN_FUNCAO_1, 25, false, false);
Button BtnFuncao2(PIN_BTN_FUNCAO_2, 25, false, false);
Button BtnFuncao3(PIN_BTN_FUNCAO_3, 25, false, false);
Button BtnFuncao4(PIN_BTN_FUNCAO_4, 25, false, false);

// Declara Contatores
Contator Bomba(PIN_BOMBA_CONTATOR);
Contator Pressurizador(PIN_PRESSURIZADOR_CONTATOR);

// Declara sensores
Sensor SensorNivelSuperior(PIN_SENSOR_NIVEL_SUPERIOR);
Sensor SensorNivelInferior(PIN_SENSOR_NIVEL_INFERIOR);
Sensor SensorNivelCritico(PIN_SENSOR_NIVEL_CRITICO);

#endif
