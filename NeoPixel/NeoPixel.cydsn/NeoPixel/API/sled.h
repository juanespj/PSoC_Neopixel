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
void `$INSTANCE_NAME`_Init(void);

#ifndef SRC_`$INSTANCE_NAME`_SLED_H_
#define SRC_`$INSTANCE_NAME`_SLED_H_
    
#include "`$INSTANCE_NAME`_pincfg.h"
#include <stddef.h>
#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "stdbool.h"

void `$INSTANCE_NAME`_sendBit(bool bitVal);
void `$INSTANCE_NAME`_sendByte(uint8_t byte);
void `$INSTANCE_NAME`_sendPixel(uint8_t r, uint8_t g, uint8_t b);
void `$INSTANCE_NAME`_show();

// Change this to be at least as long as your pixel string (too long will work fine, just be a little slower)

#define PIXELS `$NoPixels` // Number of pixels in the string

#define RES `$ResetTimeUs` // Width of the low gap between bits to cause a frame to latch

#endif //SRC_`$INSTANCE_NAME`_SLED_H_
/* [] END OF FILE */
