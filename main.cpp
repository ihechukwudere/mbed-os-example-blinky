/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE 500ms

InterruptIn mypin(BUTTON1);
// Initialise the digital pin LED1 as an output
DigitalOut led(LED1);

void button_isr(void) { led = mypin; } 

int main() {
    mypin.rise(&button_isr);
    mypin.fall(&button_isr);
  while (true) {
    printf("mypin has value : %d \n\r", !led.read());
    ThisThread::sleep_for(BLINKING_RATE);
  }
}
