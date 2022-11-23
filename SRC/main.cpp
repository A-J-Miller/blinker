#include "mbed.h"
#include "stdio.h"
#include "iostream"
#include "constants.h"
#include "tempsense.h"
#include "lightsense.h"

// Global Variables 
DigitalOut led(LED1);
    
int main()
{
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        
        float tempTherm = realTemp();
        cout << "The current temp is: " << tempTherm << "c" << endl;
        
        float tempLight = realLight();
        cout << "The current light level is: " << tempLight << "%"<< endl;
    }
}

