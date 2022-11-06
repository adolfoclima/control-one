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
#include <utils/Display.h>

// Declaração dos pinos do ESP32
const byte PIN_LED_DEBUG(2);

const byte PIN_BOMBA_CONTATOR(12);
const byte PIN_BOMBA_CORRENTE(A4);

const byte PIN_PRESSURIZADOR_CONTATOR(4);
const byte PIN_PRESSURIZADOR_CORRENTE(A5);

const byte PIN_BTN_FUNCAO_1(34);
const byte PIN_BTN_FUNCAO_2(35);
const byte PIN_BTN_FUNCAO_3(36);
const byte PIN_BTN_FUNCAO_4(39);

const byte PIN_SENSOR_NIVEL_SUPERIOR(25);
const byte PIN_SENSOR_NIVEL_INFERIOR(26);
const byte PIN_SENSOR_NIVEL_CRITICO(27);
const byte PIN_FLUXO_BOMBA(14);
const byte PIN_FLUXO_PRESSURIZADOR(13);

// Declaracao de variaveis 'bool'
static bool ledState;
// Declaração de variáveis 'byte'
byte tela=0;

// Declaração de variáveis 'Ultra longa'
long unsigned int vlr;

// Declaração de variáveis 'String'
String Vlr="";
String Funcao = "Desl";

// Declaração e Setup do display
Display *Display::pInstance = nullptr;
LiquidCrystal_I2C Display::lcd(0x27, 16, 2);

// Declara os Buttons
Button BtnFuncao1(PIN_BTN_FUNCAO_1, 25, false, false);
Button BtnFuncao2(PIN_BTN_FUNCAO_2, 25, false, false);
Button BtnFuncao3(PIN_BTN_FUNCAO_3, 25, false, false);
Button BtnFuncao4(PIN_BTN_FUNCAO_4, 25, false, false);

#endif
