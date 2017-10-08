#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x41;                  // configure P1.0,1.6 as output (and button P1.3 as input)
    P1OUT |= 0x09;                  // initialize LED to on, REN for P1.3 to pull up
    P1REN |=0x08;                   // enable P1.3 resistor connection


    while(1)
    {
        while(P1IN & BIT3){         //while button is off
            P1OUT &= ~BIT0;         //turn off LED
            P1OUT |= BIT6;
        }
        P1OUT |= BIT0;              // turn on LED
        P1OUT &= ~BIT6;
    }
}
