#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;           // give power to channel
    P1DIR |= 0x01;                  // configure P1.0 as output
    P1REN |= 0x02;                  //give P1.1 a resistor
    P1OUT |= 0x02;                  //give P1.1 a pull up resistor

    while(1)
    {
        while(P1IN & BIT1){         //while button is off
            P1OUT &= ~BIT0;         //turn off LED
        }
        P1OUT |= BIT0;              // turn on LED

    }
}
