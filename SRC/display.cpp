#include "constants.h"
#include "iostream"
#include "mbed.h"
#include "stdio.h"

extern things_t myData;
DigitalOut green(GREEN_LED);

void displayTask() {
  cout << "\033\x63"; // Clears the console
  while (true) {
    cout << "\033[H]"; // Returns the cursor to the start of the console
    if (myData.buttonState == true) {
      cout << "The button is pressed    " << endl;
      green = true;
    } else {
      cout << "The button is not pressed" << endl;
      green = false;
    }
    cout << "Current Temperature is: " << myData.tempC << "*c     " << endl;
    cout << "Current Light Level is: " << myData.light << "       " << endl;
    ThisThread::sleep_for(500ms);
  }
}