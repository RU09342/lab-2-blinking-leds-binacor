#include <msp430.h>

/**
 * blink.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Give power to inputs
    P1DIR |= 0x01;                          // Set P1.0 to output direction

    volatile unsigned int i;            // volatile to prevent optimization

    while(1) {

        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR

        for(i=100000;i>0;i--);               //delay
    }
}
