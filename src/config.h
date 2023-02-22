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
#include <WiFi.h>    // Conexão WiFi
#include <time.h>    // Biblioteca de tempo

#include <../lib/Button/Button.h> // https://github.com/JChristensen/JC_Button
#include <../lib/Contator/Contator.h>
#include <../lib/Sensor/Sensor.h>
#include <../lib/Bips/Bips.h>
#include <../lib/BuzzerPas/BuzzerPas.h>
#include <utils/Display.h>
// #include <I_RTC.h>
// #include <LittlesFS.h>

// Declaração dos pinos do ESP32
const byte PIN_LED_DEBUG(2);

const byte PIN_BOMBA_CONTATOR(12);
const byte PIN_BOMBA_CORRENTE(A4);
const byte PIN_BUZZER(15);

const byte PIN_PRESSURIZADOR_CONTATOR(4);
const byte PIN_PRESSURIZADOR_PRESSOSTATO(33);

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
byte Pulso = 0;
byte Flag = 0;
byte EstadoSeg;
byte EstadoMeioSeg;
byte AnteriorMeioSeg;
byte EstadoAnt;
byte HabilitaNivelCritico = 0;
byte StatusBombaAnterior;
byte BloqueioDoPressurizador = 0;
// Declaracao de variaveis 'Int'
int previous1Seg;
int PreviousMeioSeg;
int tempoJardim;
int tempoJardimAnt;
int TempoTotalJardim = 600;
int segundosJardim = 10;
int Alarme = 0;
int TipoAjuste = 0;
int HoraAtual = 12;
int MinAtual = 30;
int SegAtual = 0;
int TempoBomba = 0;
int TempoAlarme = 0;
int TempoPressurizador = 0;
int PreviatempoBomba = 0;
int TempoBackLigth = 1;
int TempoPausaPressao = 0;
int FrequenciaMinimaPressao = 4;

// Declaração de variáveis 'Ultra longa'
long unsigned int vlr;
long unsigned int BaseDeTempoSeg;
long unsigned int BaseDeTempoMeioSeg;
long unsigned int PreviousBaseDeTempoBuzzer;
long unsigned int BaseDeTempoBuzzer;

// Declaração de variáveis 'String'
String Vlr = "";
String VlrAnt = "";
String Funcao = "Desl";
String TelaAtual = "HOME";
String Msg = "";
String SHoraAtual = "12";
String SMinAtual = "30";
String STempoBomba;

// Vazao da bomba
float CalibracaoFatorBomba = 0.2;
float CalibracaoFatorPressurizador = 0.2;

float VazaoTotalBomba = 0.0;
float VazaoTotalPressurizador = 0.0;

volatile byte ContadorPulsoBomba = 0;
volatile byte ContadorPulsoPressurizador = 0;

volatile byte FrequenciaBomba = 0;
volatile byte FrequenciaPressurizador = 0;

byte PulsoBomba = 0;
byte PulsoPressurizador = 0;
bool EstadoBuzzer = 0;

unsigned int MililitrosBomba = 0;
unsigned int MililitrosPressurizador = 0;

enum PagesMenu
{
    Home,
    Monitor,
    Automatico,
    Jardim,
    Ajustes,
    AjustesFluxo,
    AjustesHora,
    AjustesMinuto,
    AjustesJardim,
    AjustesVazao,
    Alarmes
};

enum Ajustes
{
    TempoJardim,
    SensorFluxo,
    Hora,
    Minuto
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
BuzzerPas Buzzer(PIN_BUZZER);

// Declara sensores
Sensor SensorNivelSuperior(PIN_SENSOR_NIVEL_SUPERIOR);
Sensor SensorNivelInferior(PIN_SENSOR_NIVEL_INFERIOR);
Sensor SensorNivelCritico(PIN_SENSOR_NIVEL_CRITICO);

Sensor SensorFluxoBomba(PIN_FLUXO_BOMBA);
Sensor SensorFluxoPressurizador(PIN_FLUXO_PRESSURIZADOR);
Sensor SensorPressaoPulmao(PIN_PRESSURIZADOR_PRESSOSTATO);

#endif
