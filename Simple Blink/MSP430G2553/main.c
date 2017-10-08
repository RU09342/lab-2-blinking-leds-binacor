
#include <msp430.h> 



unsigned long limit = 100000;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x41;                  // configure P1.0 and P1.6 as output
    P1OUT |= 0x40;                  // initialize LEDs to one on and one off

    if (CALBC1_1MHZ==0xFF)                  // If calibration constant erased
      {
        while(1);                               // do not load, trap CPU!!
      }
      DCOCTL = 0;                               // Select lowest DCOx and MODx settings
      BCSCTL1 = CALBC1_1MHZ;                    // Set DCO
      DCOCTL = CALDCO_1MHZ;
      P1SEL = BIT1 + BIT2 ;                     // P1.1 = RXD, P1.2=TXD
      P1SEL2 = BIT1 + BIT2 ;                    // P1.1 = RXD, P1.2=TXD
      UCA0CTL1 |= UCSSEL_2;                     // SMCLK
      UCA0BR0 = 104;                            // 1MHz 9600
      UCA0BR1 = 0;                              // 1MHz 9600
      UCA0MCTL = UCBRS0;                        // Modulation UCBRSx = 1
      UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
      IE2 |= UCA0RXIE;                          // Enable USCI_A0 RX interrupt

    volatile unsigned int i;        // volatile to prevent optimization
    __bis_SR_register(GIE);       // Enter LPM0, interrupts enabled

    while(1)
    {
        P1OUT ^= 0x41;              // toggle P1.0 and P1.6 with XOR with 1 operation
        for(i=limit; i>0; i--);     // delay
    }
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
  while (!(IFG2&UCA0TXIFG));                // USCI_A0 TX buffer ready?
      switch(UCA0RXBUF){
      case '1':
          limit = 60000;
          break;
      case '2':
          limit = 20000;
          break;
      case '3':
          limit = 5000;
          break;
      }
}

