//
//  mcpDAC.h
//  Library for MCP4801 to MCP4922 use at AVR Atmega
//
//  Created by Michael Köhler on 18.11.18.
//  Copyright © 2018 Michael Köhler. All rights reserved.
//

#ifndef mcpDAC_h
#define mcpDAC_h

#ifdef __cplusplus
extern "C" {
#endif

#include <avr/io.h>

void mcpDACInit(volatile uint8_t *cPort, volatile uint8_t *cDDR, uint8_t cPin);
void setCSMCPDAC(volatile uint8_t *cPort, uint8_t cPin);
void unSetCSMCPDAC(volatile uint8_t *cPort, uint8_t cPin);
void spiSendByteMCPDAC(uint8_t valueToSend);
void setMCPDAC(volatile uint8_t *cPort, uint8_t cPin, uint8_t resolution, uint16_t valueToSet, uint8_t channel, uint8_t gain, uint8_t shutdown);

#ifdef __cplusplus
}
#endif
        
#endif /* mcpDAC_h */
