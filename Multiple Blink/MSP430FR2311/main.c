#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;           // give power to channel
    P1DIR |= 0x01;                  // configure P1.0 as output
    P2DIR |= 0x01;                  //configure P2.0 as output

    volatile unsigned int i;

    while(1)
    {
        P1OUT ^= 0x01;              // toggle P1.0 using XOR with 1 operation
        P2OUT ^= 0x01;              //toggle P2.0
        for(i=100000; i>0; i--);     // delay
        P1OUT ^= 0x01;              //toggle P1.0 only
        for(i=100000; i>0; i--);     // delay
    }
}
