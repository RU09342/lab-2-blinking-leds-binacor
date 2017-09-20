#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x01;                  // configure P1.0 as output
    P4DIR |= 0x80;                  // P4.7 output

    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {
        P1OUT ^= 0x01;              // toggle P1.0
        P4OUT ^= 0x80;
        for(i=50000; i>0; i--);     // delay
        P1OUT ^= 0x01;
        for(i=50000; i>0; i--);     // delay
    }
}
