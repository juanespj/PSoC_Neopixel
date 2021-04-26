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
#include "project.h"
#include <btns.h>
#define LED_ON 0u
#define LED_OFF 1u
#include "stdio.h"
/* Turn on an LED connected to a SW controlled pin */

extern DevState device;
extern uint32_t sendbuffer;
uint8_t rgb[3] = {255, 0, 0};
uint8_t ind = 0, state = 1;
uint32_t delaytmr = 0;
uint32_t counter = 0, statetmr = 0, fade = 0;
void showColor(uint8_t r, uint8_t g, uint8_t b, uint32_t delay);
void colorWipe(uint8_t r, uint8_t g, uint8_t b, uint32_t delay);
void theaterChase(uint8_t r, uint8_t g, uint8_t b, uint32_t delay);
void rainbowCycle(uint32_t frames, uint8_t frameAdvance, uint32_t pixelAdvance, uint32_t delay);
void detonate(uint8_t r, uint8_t g, uint8_t b, uint32_t startdelayms);

void device_task(void)
{
  if (device.state != device.prev_state)
  {
    device.new_state = true;
  }
  device.prev_state = device.state;
  switch (device.state)
  {
  case IDLE:
  {
    if (device.new_state)
    {
      showColor(0, 0, 0, 100);
      device.new_state = 0;
      state = 1;
    }
    showColor(rgb[0], rgb[1], rgb[2], 0);

    if (rgb[1] < 255 && state == 1)
    {
      rgb[1]++;
      rgb[0]--;
      if (rgb[1] == 255)
        state = 2;
    }
    if (rgb[2] < 255 && state == 2)
    {
      rgb[2]++;
      rgb[1]--;
      if (rgb[2] == 255)
        state = 3;
    }
    if (state == 3)
    {
      rgb[0]++;
      rgb[2]--;
      if (rgb[2] == 0)
        state = 1;
    }

    if (BTN_getPressed())
    {
      LEDA_Write(LED_ON);
      device.state = THEATER_CHASE;
    }

    break;
  }

  case THEATER_CHASE:
  {
    if (device.new_state)
    {
      showColor(0, 0, 0, 100);
      device.new_state = 0;
      state = 1;
      delaytmr = 0;
    }
    if (BTN_getPressed())
    {
      state += 1;
      if (state > 3)
      {
        state = 1;
      }
    }
    if (BTN_getHeld())
    {
      device.state = RAINBOW;
    }
    // Send a theater pixel chase in...
    switch (state)
    {
    case 1:
      theaterChase(127, 127, 127, 500); // White
      break;
    case 2:
      theaterChase(127, 0, 0, 250); // Red
      break;
    case 3:
      theaterChase(0, 0, 127, 100); // Blue
      break;
    }

    break;
  }
  case RAINBOW:
  {
    if (device.new_state)
    {
      showColor(0, 0, 0, 100);
      device.new_state = 0;
    }

    rainbowCycle(1000, 20, 5, 500);
    if (BTN_getPressed())
    {
      device.state = EXPLODE;
    }
    break;
  }
  case EXPLODE:
  {
    if (device.new_state)
    {
      showColor(0, 0, 0, 100);
      device.new_state = 0;
      delaytmr = 0;
      state = 1;
      fade = 255;
    }
    detonate(255, 255, 255, 1000);
    if (BTN_getPressed())
    {
      device.state = IDLE;
    }
    break;
  }
  }
}

int main(void)
{
  CyGlobalIntEnable; /* Enable global interrupts. */
  device.state = IDLE;
  device.new_state = true;
  uint32_t ticks = 0;
  NeoPixel_Init();
  for (;;)
  {
    BTN_task();
    device_task();
    if (ticks > 1000)
    { //HeartBeat
      LEDA_Write(!LEDA_Read());
      ticks = 0;
    }
    ticks += 1;
  }
}

// Display a single color on the whole string
void showColor(uint8_t r, uint8_t g, uint8_t b, uint32_t delay)
{
  if (delaytmr == 0)
  {
    for (int p = 0; p < PIXELS; p++)
    {
      NeoPixel_sendPixel(r, g, b);
    }
    NeoPixel_show();
    delaytmr = delay * 10;
  }
  if (delaytmr > 0)
  {
    delaytmr--;
  }
}

// Fill the dots one after the other with a color
// rewrite to lift the compare out of the loop
void colorWipe(uint8_t r, uint8_t g, uint8_t b, uint32_t delay)
{
  if (delaytmr == 0)
  {
    for (uint32_t i = 0; i < PIXELS; i += (PIXELS / 5))
    {

      uint32_t p = 0;
      while (p++ <= i)
      {
        NeoPixel_sendPixel(r, g, b);
      }
      while (p++ <= PIXELS)
      {
        NeoPixel_sendPixel(0, 0, 0);
      }
      NeoPixel_show();
      delaytmr = delay * 10;
    }
  }
  if (delaytmr > 0)
  {
    delaytmr--;
  }
}

// Theatre-style crawling lights.
// Changes spacing to be dynmaic based on string size

#define THEATER_SPACING (PIXELS / 5)
uint32_t q = 0;
void theaterChase(uint8_t r, uint8_t g, uint8_t b, uint32_t delay)
{
  if (q == THEATER_SPACING)
  {
    q = 0;
  }
  if (delaytmr == 0)
  {
    for (uint32_t i = 0; i < PIXELS; i++)
    {
      if ((i + q) % THEATER_SPACING == 0)
      {
        NeoPixel_sendPixel(r, g, b);
      }
      else
      {
        NeoPixel_sendPixel(0, 0, 0);
      }
    }
    NeoPixel_show();
    delaytmr = delay * 10;
    q++;
  }
  if (delaytmr > 0)
  {
    delaytmr--;
  }
}

// I rewrite this one from scrtach to use high resolution for the color wheel to look nicer on a *much* bigger string
uint32_t firstPixelHue = 0; // Color for the first pixel in the string

void rainbowCycle(uint32_t frames, uint8_t frameAdvance, uint32_t pixelAdvance, uint32_t delay)
{

  // Hue is a number between 0 and 3*256 than defines a mix of r->g->b where
  // hue of 0 = Full red
  // hue of 128 = 1/2 red and 1/2 green
  // hue of 256 = Full Green
  // hue of 384 = 1/2 green and 1/2 blue
  // ...
  if (firstPixelHue == frames)
  {
    firstPixelHue = 0;
  }

  if (delaytmr == 0)
  {
    unsigned int currentPixelHue = firstPixelHue;
    for (uint32_t i = 0; i < PIXELS; i++)
    {
      if (currentPixelHue >= (3 * 256))
      { // Normalize back down incase we incremented and overflowed
        currentPixelHue -= (3 * 256);
      }
      uint8_t phase = currentPixelHue >> 8;
      uint8_t step = currentPixelHue & 0xff;
      switch (phase)
      {
      case 0:
        NeoPixel_sendPixel(~step, step, 0);
        break;

      case 1:
        NeoPixel_sendPixel(0, ~step, step);
        break;

      case 2:
        NeoPixel_sendPixel(step, 0, ~step);
        break;
      }

      currentPixelHue += pixelAdvance;
    }

    NeoPixel_show();
    firstPixelHue += frameAdvance;
    delaytmr = delay * 10;
  }
  if (delaytmr > 0)
  {
    delaytmr--;
  }
}

// I added this one just to demonstrate how quickly you can flash the string.
// Flashes get faster and faster until *boom* and fade to black.
void detonate(uint8_t r, uint8_t g, uint8_t b, uint32_t delay)
{
  if (counter == 0 && state < 3)
  {
    delaytmr = 0;
    if (state == 1)
    {
      showColor(r, g, b, 0); // Flash the color
      state = 0;
    }
    else
    {
      showColor(0, 0, 0, 0);
      state = 1;
    }
    statetmr = statetmr / 1.2; //gradually reduced delay
    counter = statetmr;

    if (statetmr == 1)
    {      showColor(0, 0, 0, 0);//black before explosion
      fade = 256;
      state = 3;
      counter = delay * 500;
    }
    if (statetmr == 0)
    { ///start
      statetmr = delay * 300;
      counter = 0;
    }
  }
  if (counter > 0)
  {
    counter--;
  }
  if (counter == 0 && state == 3)
  {
    // Then we fade to black....
    
    showColor((r * fade) / 256, (g * fade) / 256, (b * fade) / 256, 0);
    
    if (fade > 0)
    {
      fade--;
    }
    counter = delay /10;
    if (fade == 0)
    {
      showColor(0, 0, 0, 0);
      statetmr = delay * 500;
      counter = statetmr;
      state = 1;
    }
  }
}
/* [] END OF FILE */
