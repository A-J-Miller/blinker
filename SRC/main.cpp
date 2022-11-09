#include "mbed.h"
#include "stdio.h"
#include "iostream"
#include "constants.h"
#include "tempsense.h"

// Global Variables 
DigitalOut led(LED1);
    
int main()
{
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        float tempTherm = realTemp();
        cout << "The current temp is: " << tempTherm << "c" << endl;
    }
}

