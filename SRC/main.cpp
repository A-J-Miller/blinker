#include "button.h"
#include "constants.h"
#include "iostream"
#include "lightsense.h"
#include "mbed.h"
#include "stdio.h"
#include "tempsense.h"
#include "display.h"


// Global Variables
DigitalOut led(LED1);
things_t myData;

Thread realTempHandle;
Thread realLightSenseHandle;
Thread buttonHandle;
Thread displayHandle;

int main() {

  realTempHandle.start(callback(realTemp));
  realLightSenseHandle.start(callback(realLight)); 
  buttonHandle.start(callback(readButtonState));
  displayHandle.start(callback(displayTask));

      while (true) {
    led = !led;
    ThisThread::sleep_for(BLINKING_RATE);
  }
}