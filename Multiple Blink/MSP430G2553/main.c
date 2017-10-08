#include <msp430.h> 


/**
 * multi LED counter - pins 1.0 to 1.5
 */
 main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x1F;                  // configure P1.0 thru P1.5 output

    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {
        if(P1OUT == 0x1F){
            P1OUT = 0x00;
        }else{
            P1OUT++;
        }
        for(i=20000; i>0; i--);     // delay
    }
}
