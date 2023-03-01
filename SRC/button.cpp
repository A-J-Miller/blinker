#include "button.h"
#include "constants.h"
#include "iostream"
#include "mbed.h"

DigitalIn userButton(PUSH_BUTTON);
extern things_t myData;

void readButtonState() {
  bool lastButtonState = userButton;
  bool pressed = false;
  while (true) {
    if (userButton == true) {
      pressed = true;
    }
    if (userButton == false && pressed == true) {
      myData.buttonState = !myData.buttonState;
      pressed = false;
    }
    ThisThread::sleep_for(500);
  }
}