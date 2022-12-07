#include "constants.h"
#include "iostream"
#include "mbed.h"
#include "stdio.h"

extern things_t myData;
DigitalOut green(GREEN_LED);

void displayTask() {
  while (true) {
    if (myData.buttonState == true) {
      cout << "The button is pressed" << endl;
      green = true;
    } else {
      cout << "The button is not pressed" << endl;
      green = false;
    }
    ThisThread::sleep_for(500ms);
  }
}