/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
void NeoPixel_Init(void);

#ifndef SRC_NeoPixel_SLED_H_
#define SRC_NeoPixel_SLED_H_
    
#include "NeoPixel_pincfg.h"
#include <stddef.h>
#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "stdbool.h"

void NeoPixel_sendBit(bool bitVal);
void NeoPixel_sendByte(uint8_t byte);
void NeoPixel_sendPixel(uint8_t r, uint8_t g, uint8_t b);
void NeoPixel_show();

// Change this to be at least as long as your pixel string (too long will work fine, just be a little slower)

#define PIXELS 25 // Number of pixels in the string

#define RES 260 // Width of the low gap between bits to cause a frame to latch

#endif //SRC_NeoPixel_SLED_H_
/* [] END OF FILE */
