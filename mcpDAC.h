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
/**********************************************
Public Function: mcpADCInit

Purpose: Initialise SPI interface

Input Parameter:
-volatile uint8_t *cPort:  Pointer to PORT-register of CS-pin
-volatile uint8_t *cDDR:   Pointer to DDR-register of CS-pin
- uint8_t cPin:            Portpin of CS-pin

Return Value: none
**********************************************/
void mcpDACInit(volatile uint8_t *cPort, volatile uint8_t *cDDR, uint8_t cPin);
        
/**********************************************
 Public Function: setCSMCPADC
 
 Purpose: set CS of MCPADC
 
 Input Parameter:
 -volatile uint8_t *cPort:  Pointer to PORT-register of CS-pin
 - uint8_t cPin:            Portpin of CS-pin
 
 Return Value: none
 **********************************************/
void setCSMCPDAC(volatile uint8_t *cPort, uint8_t cPin);

/**********************************************
 Public Function: unSetCSMCPADC
 
 Purpose: clear CS of MCPADC
 
 Input Parameter:
 -volatile uint8_t *cPort:  Pointer to PORT-register of CS-pin
 - uint8_t cPin:            Portpin of CS-pin
 
 Return Value: none
 **********************************************/
        
void unSetCSMCPDAC(volatile uint8_t *cPort, uint8_t cPin);
/**********************************************
 Public Function: spiSendByteMCPADC
 
 Purpose: send byte to MCPADC
 
 Input Parameter:
 -volatile uint8_t valueToSend:  value to send to MCPADC
 
 Return Value: none
 **********************************************/
void spiSendByteMCPDAC(uint8_t valueToSend);
        
/**********************************************
 Public Function: getMCPADC
 
 Purpose: get ADC value from designated channel
 
 Input Parameter:
 -volatile uint8_t *cPort:  Pointer to PORT-register of CS-pin
 -uint8_t cPin:             Portpin of CS-pin
 -uint8_t channel:          designated channel
 -uint8_t mode:             0 for differential mode, 1 for single-ended mode
 
 Return Value:
 -uint16_t returnValue:     ADC-value from designated channel
 **********************************************/
void setMCPDAC(volatile uint8_t *cPort, uint8_t cPin, uint8_t resolution, uint16_t valueToSet, uint8_t channel, uint8_t gain, uint8_t shutdown);

#ifdef __cplusplus
}
#endif
        
#endif /* mcpDAC_h */
