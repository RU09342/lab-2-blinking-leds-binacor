#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x41;                  // configure P1.0 and P1.6 as output
    P1OUT |= 0x40;                  // initialize LEDs to one on and one off

    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {
        P1OUT ^= 0x41;              // toggle P1.0 and P1.6 with XOR with 1 operation
        for(i=100000; i>0; i--);     // delay
    }
}
