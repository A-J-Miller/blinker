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
    ThisThread::sleep_for(500ms);
  }
}