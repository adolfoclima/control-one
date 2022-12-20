// Adolfo Lima
// Programa legal

#include <config.h>
#include <loop.h>
#include <pages/Pages.h>

void setup()
{
  // Inicializa o Display
  Display::Instance();

  // Criando Buttons
  BtnFuncao1.begin(); // initialize the button object
  BtnFuncao2.begin(); // initialize the button object
  BtnFuncao3.begin(); // initialize the button object
  BtnFuncao4.begin(); // initialize the button object

  // Criando Contatores
  Bomba.begin();
  Pressurizador.begin();

  // Criando Sensores
  SensorNivelSuperior.begin();
  SensorNivelInferior.begin();
  SensorNivelCritico.begin();
  SensorFluxoBomba.begin();
  SensorFluxoPressurizador.begin();

  // Setup de saída
  pinMode(PIN_LED_DEBUG, OUTPUT);
  // pinMode(PIN_BOMBA_CONTATOR, OUTPUT);
  // pinMode(PIN_PRESSURIZADOR_CONTATOR, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  // Setup de entrada
  pinMode(PIN_BOMBA_CORRENTE, INPUT); // Entrada analogica

  // Tela de Display
  Pages::Splash.Print();
  // Pages::Home.Print();
}