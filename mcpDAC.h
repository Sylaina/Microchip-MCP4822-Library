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
 Public Function: mcpDACInit
 
 Purpose: Initialise SPI interface
 
 Input Parameter:
 -volatile uint8_t *cPort:  Pointer to PORT-register of CS-pin
 -volatile uint8_t *cDDR:   Pointer to DDR-register of CS-pin
 - uint8_t cPin:            Portpin of CS-pin
 
 Return Value: none
 **********************************************/
void mcpDACInit(volatile uint8_t *cPort, volatile uint8_t *cDDR, uint8_t cPin);
        
/**********************************************
Public Function: setCSMCPDAC
     
Purpose: set CS of MCPDAC
     
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
 Public Function: spiSendByteMCPDAC
 
 Purpose: send byte to MCPDAC
 
 Input Parameter:
 -volatile uint8_t valueToSend:  value to send to MCPDAC
 
 Return Value: none
 **********************************************/
void spiSendByteMCPDAC(uint8_t valueToSend);
        
/**********************************************
 Public Function: setMCPDAC
 
 Purpose: set designated outputport to value with gain or deactivate/power down chip
 
 Input Parameter:
 -volatile uint8_t *cPort:  Pointer to PORT-register of CS-pin
 -uint8_t cPin:             Portpin of CS-pin
 -uint8_t resolution:       Resolution of Chip in bit
 -uint16_t  valueToSet:     value for output
 -uint8_t channel:          outputport, 1 for port a, 2 for port b
 -uint8_t gain:             gain for designated port, 1 for 1x, 2 for 2x
 -uint8_t shutdown:         0 for activate chip, 1 for power down chip
 
 Return Value: none
 **********************************************/
void setMCPDAC(volatile uint8_t *cPort, uint8_t cPin, uint8_t resolution, uint16_t valueToSet, uint8_t channel, uint8_t gain, uint8_t shutdown);

#ifdef __cplusplus
}
#endif
        
#endif /* mcpDAC_h */
