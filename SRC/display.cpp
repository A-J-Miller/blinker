#include "constants.h"
#include "iostream"
#include "mbed.h"
#include "stdio.h"
#include "vt100.h"
#include <iomanip>

extern things_t myData;
DigitalOut green(GREEN_LED);
DigitalOut yellow(YELLOW_LED);
DigitalOut red(RED_LED);

void displayTask() {
  cout << setprecision(1) << fixed;
  printf("\033[2J");          // Clears the console
  ThisThread::sleep_for(500); // Sleep to allow console time to clear
  printf("\033[?25l");        // Hides the cursor

  while (true) {
    cout << "\033[H"; // Returns the cursor to the start of the console
    if (myData.buttonState == true) {
      cout << "The door is: "
           << "\033[0;32m"
           << "OPEN    "
           << "\033[0;37m" << endl;
      green = true;
    } else {
      cout << "The door is: closed" << endl;
      green = false;
    }
    cout << "Current Temperature is: " << myData.tempC << "*c     " << endl;

    if (myData.tempOR == true) {
      cout << "Heater Status: "
           << "\033[1;33m"
           << "OVERRIDE ON"
           << "\033[0;37m" 
           << endl;
      red = true;
    } else {
        red = false;
      if (myData.heaterState == true) {
        cout << "Heater Status: "
             << "\033[42m"
             << "  "
             << "\033[40m"
             << "                 " << endl;
        yellow = true;
      } else {
        cout << "Heater Status: "
             << "\033[41m"
             << "  "
             << "\033[40m"
             << "                 " << endl;
        yellow = false;
      }
    }
    cout << "Heater Active at: " << myData.setTemp << "*c     " << endl;

    cout << "\033[0;34m"
         << "   Low "
         << "\033[0;37m"
         << "Temperature Reading is:  " << myData.tempCMin << "*c     " << endl;
    cout << "\033[0;31m"
         << "   High "
         << "\033[0;37m"
         << "Temperature Reading is: " << myData.tempCMax << "*c     " << endl;
    cout << "Current Light Level is: " << myData.light << "%      "
         << endl; // Note the spaces added to clear artifacts
    cout << "Light Activation Level: " << myData.setLight << "%      " << endl;
    if (myData.lightState == true) {
      cout << "Light Status: "
           << "\033[42m"
           << "  "
           << "\033[40m" << endl;
    } else {
      cout << "Light Status: "
           << "\033[41m"
           << "  "
           << "\033[40m" << endl;
    }
    ThisThread::sleep_for(500);
  }
}