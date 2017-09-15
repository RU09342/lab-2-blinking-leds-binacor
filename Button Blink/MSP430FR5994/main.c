#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;           // give power to channel
    P1DIR |= 0x01;                  // configure P1.0 as output
    P5DIR |= 0x00;
    P5REN |= 0x20;                  //give P5.5 a resistor
    P5OUT |= 0x20;                  //give P5.5 a pull up resistor

    while(1)
    {
        while(P5IN & BIT5){
            P1OUT &= ~BIT0;
        }
        P1OUT |= BIT0;              // toggle P1.0 with XOR with 1 operation

    }
}
