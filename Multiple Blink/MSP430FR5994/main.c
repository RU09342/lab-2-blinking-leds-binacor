#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;           // give power to channel
    P1DIR |= 0x03;                  // configure P1.0 and P1.1 as output

    volatile unsigned int i;

    while(1)
    {
        P1OUT ^= 0x03;              // toggle P1.0 and P1.1 using XOR with 1 operation
        for(i=100000; i>0; i--);     // delay
        P1OUT ^= 0x01;              //toggle P1.0 only
        for(i=100000; i>0; i--);     // delay
    }
}
