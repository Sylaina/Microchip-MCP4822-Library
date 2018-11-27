# Microchip-MCP4822-Library
Library for MCP4822 at AVR Mikrocontroller

This library is for use DAC MCP4822 on AVR Mikrocontroller like Atmega328 via SPI.
I've wrote this library because I just found libraries for Arduino (C++ Language) and I needed a library for C-Language (don't use Arduino).
My library shut work for Arduino/C++ too. (not tested).

The library is tested with MCP4822, should work with the follow DACs too:

<b>MCP4801, MCP4811, MCP4821, MCP4802, MCP4812, MCP4901, MCP4911, MCP4921, MCP4902, MCP4912, MCP4922</b>

<h3>Examble for Atmega328P:</h3>

MCP4822 connected at SPI-pins of Atmega328P, CS-pin connected PB2 of Atmega328P

```c
#include <avr/io.h>
#include <util/delay.h>
#include "mcpDAC.h"

int main(void){
  mcpDACInit(&PORTB, &DDRB, PB2);
  
  for(;;){
    // Set OUTA of MCP4822 to 500mV
    setMCPDAC(&PORTB, // Port of CS-pin
              PB2,    // CS-pin
              12,     // resolution of DAC
              1000,   // count
              1,      // channel, 1 means OUTA, 2 means OUTB
              1,      // gain, out voltage of DAC is 2048 mV / 4096 * gain * count
              0);     // chip shutdown=0 mean chip on, shutdown=1 means chip off
    // set OUTB of MCP4822 to 500mV
    setMCPDAC(&PORTB,
              PB2,
              12,
              500,
              2,
              2,
              0);
     delay_ms(500);
     // Set OUTA of MCP4822 to 1500mV
     setMCPDAC(&PORTB, 
               PB2,
               12,
               1500,   
               1,    
               2,    
               0);   
     // set OUTB of MCP4822 to 1500mV
     setMCPDAC(&PORTB,
               PB2,
               12,
               3000,
               2,
               1,
               0);
     delay_ms(500);
  }
  return 0; // never reached
}
```
