//
//  mcpDAC.c
//  
//
//  Created by Michael Köhler on 18.11.18.
//  Copyright © 2018 Michael Köhler. All rights reserved.
//

#include "mcpDAC.h"

void mcpDACInit(volatile uint8_t *cPort, volatile uint8_t *cDDR, uint8_t cPin){
    *cDDR |= (1 << cPin);
    *cPort |= (1 << cPin);
    DDRB |= (1 << PB2)|(1 << PB3)|(1 << PB5);
    SPCR = (1 << SPE)|(1<<MSTR)|(1<<SPR0);
}

void setCSMCPDAC(volatile uint8_t *cPort, uint8_t cPin){
    *cPort &= ~(1 << cPin);
}

void unSetCSMCPDAC(volatile uint8_t *cPort, uint8_t cPin){
    *cPort |= (1 << cPin);
}

void spiSendByteMCPDAC(uint8_t valueToSend){
    SPDR = valueToSend;
    while(!(SPSR & (1<<SPIF)));
}

void setMCPDAC(volatile uint8_t *cPort, uint8_t cPin, uint8_t resolution, uint16_t valueToSet, uint8_t channel, uint8_t gain, uint8_t shutdown){
    setCSMCPDAC(cPort,
                 cPin);
    switch (resolution) {
        case 12:
            spiSendByteMCPDAC(((valueToSet>>8)&0xff)
                              | ((channel-1) << 7)
                              | ((2-gain) << 5)
                              | ((1-shutdown) << 4)
                              );
            spiSendByteMCPDAC( valueToSet & 0xff );
            break;
        case 10:
            spiSendByteMCPDAC(((valueToSet>>6)&0xff)
                              | ((channel-1) << 7)
                              | ((2-gain) << 5)
                              | ((1-shutdown) << 4)
                              );
            spiSendByteMCPDAC( (valueToSet<<2) & 0xff );
            break;
        case 8:
            spiSendByteMCPDAC(((valueToSet>>4)&0xff)
                              | ((channel-1) << 7)
                              | ((2-gain) << 5)
                              | ((1-shutdown) << 4)
                              );
            spiSendByteMCPDAC( (valueToSet<<4) & 0xff );
            break;
        default:
            break;
    }
    unSetCSMCPDAC(cPort,
                   cPin);
}
