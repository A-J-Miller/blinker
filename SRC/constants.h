#ifndef constants_h
#define constants_h

#define BLINKING_RATE       2000
#define THERM_OUT           P10_1
#define GREEN_LED           P0_5
#define YELLOW_LED          P10_5
#define RED_LED             P10_2
#define PUSH_BUTTON         P10_3
#define LIGHT_IN            P10_4
#define RXLED               P12_3

/* Reference resistor in series with the thermistor is of 10kohm */
#define R_REFERENCE                         (float)(10000)
/* A constant of NCP18XH103F03RB thermistor is */
#define A_COEFF                          (float)(0.0009032679f)
/* B constant of NCP18XH103F03RB thermistor is */
#define B_COEFF                          (float)(0.000248772f)
/* C constant of NCP18XH103F03RB thermistor is */
#define C_COEFF                          (float)(0.0000002041094f)

/* Zero Kelvin in degree C */
#define ABSOLUTE_ZERO                       (float)(-273.15)

struct things_t {
    float tempC;
    float tempCMax;
    float tempCMin = 1000;
    float setTemp = 26.0;
    bool heaterState;
    bool heaterOverride;

    float light;
    float setLight = 50.0;
    bool lightState;

    bool buttonState;
};

#endif //constants.h