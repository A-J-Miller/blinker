/*
This code is designed to read the voltage of the on-board thermistor and convert
the reading into degrees C. The output is then displayed via console
*/

#include "lightsense.h"
#include "constants.h"
#include "iostream"
#include "mbed.h"

AnalogIn lightsenseVoltage(LIGHT_IN);
extern things_t myData;

void realLight() {
  while (true) {
    myData.light = lightsenseVoltage.read() * 100;
    
    if (myData.light > myData.setLight+2.0){
        myData.lightState = false; //Change lightState to false if light level + 2% is exceeded
    }
    else if (myData.light < myData.setLight-2.0){
        myData.lightState = true; //Change lightState to true if light level - 2% is exceeded
    }
    ThisThread::sleep_for(500ms);
  }
}