# Off Board Blink
Russell Binaco: 
The off-board blink simply runs the MSP430G2553's simple blink code, with the G2553 chip powered by an off-board circuit.

First, a 10uF bulk capacitor and 100pF bypass capacitor are connected in parallel with the chip.
The reset circuit consists of a button in parallel with a 100pF capacitor connected between the reset pin and ground.
The LED circuit connects P1.0 to ground, in series with a 100ohm resistor to limit the current.
The power source is a 3.3V power supply.
Image and video of the circuit are attached in the lab2 folder.

