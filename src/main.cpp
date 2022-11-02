// Adolfo Lima
// Programa legal

#include <config.h>
#include <setup.h>

void loop()
{
  static bool ledState; // a variable that keeps the current LED status
  Button_1.read();      // read the button
  Button_2.read();      // read the button

  // if (Button_1.isPressed())
  // {
  //   digitalWrite(PIN_LED_1, true);
  // }
  // else
  // {
  //   digitalWrite(PIN_LED_1, false);
  // }

  if (Button_1.wasPressed()) // if the button was released, change the LED state
  {
    ledState = !ledState;
    digitalWrite(PIN_LED_1, ledState);
  }

  // if (Button_1.wasReleased()) // if the button was released, change the LED state
  // {
  //   ledState = !ledState;
  //   digitalWrite(PIN_LED_1, ledState);
  // }

  // if (Button_1.pressedFor(2000))
  // {
  //   // button has been pressed for one second
  //   digitalWrite(PIN_LED_1, true);
  // }

  // if (Button_2.pressedFor(2000))
  // {
  //   // button has been pressed for one second
  //   digitalWrite(PIN_LED_1, false);
  // }
}