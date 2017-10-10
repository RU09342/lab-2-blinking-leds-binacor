# Multiple Blink
Russell Binaco: 
Multiple Blink uses two for-loop delays to have two LEDs blink at different rates.
All boards successfully implement multiple blink.

## Extra Work
### Even More LEDs / Patterned Lights
The MSP430G2553 uses the first five pins of port 1 to implement a binary five-bit counter rather than just blink two LEDs. This is done by incrementing P1OUT with a limit of 0x1F. An image and a video are attached in the lab2 directory titled Multiple Blink.
