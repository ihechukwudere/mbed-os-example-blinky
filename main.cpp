/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


DigitalIn mypin(BUTTON1);

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    
    while (true) {
        led = mypin;
         printf("mypin has value : %d \n\r", !led.read());
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
