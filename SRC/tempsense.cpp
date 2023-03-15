/*
This code is designed to read the voltage of the on-board thermistor and convert
the reading into degrees C. The output is then displayed via console
*/

#include "tempsense.h"
#include "constants.h"
#include "iostream"
#include "mbed.h"
#include "wifiTask.h"

// Therm Variables - reads therm voltage
AnalogIn tempVoltage(THERM_OUT);
extern things_t myData;

void realTemp() {

  // vdd = true;
  // gnd = false; //Thermistor Enabled
  // vdd = false; //Thermistor Disabled

  while (true) {

    float refVoltage =
        tempVoltage.read() * 2.4; // Range of ADC 0->2*Vref (Takes a Reading)
    float refCurrent = refVoltage / 10000.0; // 10k Reference Resistor
    float thermVoltage = 3.3 - refVoltage;   // Assume supply voltage is 3.3v
    float thermResistance = thermVoltage / refCurrent;
    float logrT = (float32_t)log((float64_t)thermResistance);

    /* Calculate temperature from the resistance of thermistor using
     * Steinhart-Hart Equation */
    float stEqn = (float32_t)((A_COEFF) + ((B_COEFF)*logrT) +
                              ((C_COEFF)*pow((float64)logrT, (float32)3)));
    float temperatureC = (float32_t)(((1.0 / stEqn) + ABSOLUTE_ZERO) + 0.05);

    myData.tempC = temperatureC;

    if (myData.tempC > myData.setTemp + 1.0) {
      myData.heaterState =
          false; // Change heaterState to false if temp + 2*c is exceeded
    } else if (myData.tempC < myData.setTemp - 1.0) {
      myData.heaterState =
          true; // Change heaterState to true if temp - 2*c is exceeded
    }

    if (temperatureC > myData.tempCMax) {
      myData.tempCMax = temperatureC;
    }

    if (temperatureC < myData.tempCMin) {
      myData.tempCMin = temperatureC;
    }
    
    int pubRate;
    if (pubRate++ > 20) {
      sendPub(TEMPERATURE_TOPIC, myData.tempC);
      pubRate = 0;
    }

    ThisThread::sleep_for(500);
  }
  //    return temperatureC;
}