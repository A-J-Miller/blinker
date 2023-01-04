#include "constants.h"
#include "iostream"
#include "mbed.h"
#include "stdio.h"
#include "vt100.h"

extern things_t myData;
DigitalOut green(GREEN_LED);

void displayTask() {
  cout << "\033\x63"; // Clears the console
  ThisThread::sleep_for(500ms); // Sleep to allow console time to clear
  cout << "\033[?25l"; // Hides the cursor

  while (true) {
    cout << "\033[H"; // Returns the cursor to the start of the console
    if (myData.buttonState == true) {
      cout << "The button is " << "\033[0;32m" << "pressed    " << "\033[0;37m" << endl;
      green = true;
    } else {
      cout << "The button is not pressed" << endl;
      green = false;
    }
    cout << "Current Temperature is: " << myData.tempC << "*c     " << endl;
    cout << "\033[0;34m" << "   Low " << "\033[0;37m" << "Temperature Reading is:  " << myData.tempCMin << "*c     " << endl;
    cout << "\033[0;31m" << "   High " << "\033[0;37m" << "Temperature Reading is: " << myData.tempCMax << "*c     " << endl;
    cout << "Current Light Level is: " << myData.light << "       " << endl; // Note the spaces added to clear artifacts
    ThisThread::sleep_for(500ms);
  }
}