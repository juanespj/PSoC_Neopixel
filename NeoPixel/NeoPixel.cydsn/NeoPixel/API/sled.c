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
/*
 This is an example of how simple driving a Neopixel can be
 This code is optimized for understandability and changability rather than raw speed
 More info at http://wp.josh.com/2014/05/11/ws2812-neopixels-made-easy/
*/

#include "`$INSTANCE_NAME`_sled.h"
#include "`$INSTANCE_NAME`_pixl.h"
void `$INSTANCE_NAME`_sendBit(bool bitVal)
{   
  if (bitVal)
  { // 0 bit
    CY_SYS_PINS_SET_PIN(`$INSTANCE_NAME`_pixl__DR, `$INSTANCE_NAME`_pixl_SHIFT); 
    CyDelayCycles(2);
    CY_SYS_PINS_CLEAR_PIN(`$INSTANCE_NAME`_pixl__DR, `$INSTANCE_NAME`_pixl_SHIFT);
    CyDelayCycles(1);
  }
  else
  { // 1 bit
      CY_SYS_PINS_SET_PIN(`$INSTANCE_NAME`_pixl__DR, `$INSTANCE_NAME`_pixl_SHIFT);            
      CY_SYS_PINS_CLEAR_PIN(`$INSTANCE_NAME`_pixl__DR, `$INSTANCE_NAME`_pixl_SHIFT);
      CyDelayCycles(1);
  } 
}

void `$INSTANCE_NAME`_sendByte(uint8_t byte)
{
for( uint8_t bit =8 ; bit > 0 ; bit-- ) {
    `$INSTANCE_NAME`_sendBit( (byte>>(bit-1))&0x01u );   ; // Neopixel wants bit in highest-to-lowest 
    byte <<= 1;                            
  }
}

/*
  The following three functions are the public API:  
  ledSetup() - set up the pin that is connected to the string. Call once at the begining of the program.  
  sendPixel( r g , b ) - send a single pixel to the string. Call this once for each pixel in a frame.
  show() - show the recently sent pixel on the LEDs . Call once per frame.   
*/

void `$INSTANCE_NAME`_sendPixel(uint8_t r, uint8_t g, uint8_t b)
{
  `$INSTANCE_NAME`_sendByte(g); // Neopixel wants colors in green then red then blue order
  `$INSTANCE_NAME`_sendByte(r);
  `$INSTANCE_NAME`_sendByte(b);
}

// Just wait long enough without sending any bots to cause the pixels to latch and display the last sent frame

void `$INSTANCE_NAME`_show()
{
  CyDelayUs(RES ); // Round up since the delay must be _at_least_ this long (too short might not work, too long not a problem)
}

void `$INSTANCE_NAME`_Init(void)
{

}

/* [] END OF FILE */
