#include "mbed.h"
#include "constants.h"
#include "button.h"
#include "iostream"

DigitalIn userButton(PUSH_BUTTON);

bool readButtonState() {
    return !(bool)userButton;

}