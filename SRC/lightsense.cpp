/* 
This code is designed to read the voltage of the on-board thermistor and convert the reading into degrees C. 
The output is then displayed via console
*/

#include "mbed.h"
#include "constants.h"
#include "lightsense.h"
#include "iostream"


AnalogIn lightsenseVoltage(LIGHT_IN);

float realLight() {
    float lightLevel = lightsenseVoltage.read() * 100;

return lightLevel;
}