#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE 500ms

InterruptIn mypin(BUTTON1);
// Initialise the digital pin LED1 as an output
DigitalOut led(LED1);

// Toggles LED1 state
void button_isr(void) { led = !mypin; } 

int main() {
    mypin.rise(&button_isr); // powers the LED1 off
    mypin.fall(&button_isr); // powers the LED1 on
    led = mypin; // Turn on the LED1 on the first press of BUTTON1
  while (true) {
    printf("mypin has value : %d \n\r", !led.read());
    ThisThread::sleep_for(BLINKING_RATE);
  }
}
