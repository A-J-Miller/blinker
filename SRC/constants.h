#ifndef constants_h
#define constants_h

// Blinking rate in milliseconds
#define BLINKING_RATE     2s
#define THERM_OUT         P10_1
#define THERM_VDD         P10_3
#define THERM_GND         P10_0

#define GREEN_LED         P0_5
#define PUSH_BUTTON       P0_4

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

#define LIGHT_IN P10_4

#endif //constants.h