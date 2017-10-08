#include <msp430.h> 


/**
 * main.c
 */
main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Give power to inputs
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P9DIR |= 0x80;                          //Set P9.7 to output

    volatile unsigned int i;            // volatile to prevent optimization

    while(1) {

        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
        P9OUT ^= 0x80;                      //Toggle P9.7
        for(i=50000;i>0;i--);               //delay
        P1OUT ^= 0x01;
        for(i=50000;i>0;i--);               //delay
    }
}
