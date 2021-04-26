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
#define BTNS_H_
#include <btns.h>
#include <project.h>

DevState device;
/**
 * @fn bool BTN_getPressed ( BTN_NAMES_t button )
 * @param button the button name to read
 * @return true if an unacknowledged press has occurred
 *
 * This function will check the acknowledged flag for a given button
 * and return the appropriate value. If a press has been acknowledged
 * (by calling this function) then then the current press is not
 * returned.
 *
 * Presses are persistent until read!
 */
bool BTN_getPressed()
{
	bool result = false;
	if (device.btn.isPressed)
	{
		//------------------------------------------------------
		// only return the press if not acknowledged
		//------------------------------------------------------
		if (!device.btn.isAcknowledged)
		{
			result = true;
			device.btn.isAcknowledged = true;
		}
	}

	return result;
}

/**
 * @fn bool BTN_getHeld ( BTN_NAMES_t button )
 * @param button the name of the button to read
 * @return true if the button is held
 *
 * This function will return the value of the held flag. Releasing the
 * button clears the flag. There is no time base on held events.
 */
bool BTN_getHeld()
{
	return device.btn.isHeld;
}

void BTN_task(void)
{

	//--------------------------------------------
	// get the values from the GPIO
	device.btn.sense = !BTN_Read();

	//--------------------------------------------
	// software debounce for press / hold events.
	//--------------------------------------------
	if (device.btn.sense == 1)
	{
		if (device.btn.timer < BTN_HOLD_TIME)
		{
			device.btn.timer += BTN_TICK_TIME;
		}
		else
		{
			device.btn.isHeld = true;
		}

		if (device.btn.timer > BTN_PRESS_MSEC)
		{
			if (!device.btn.isAcknowledged)
			{
				device.btn.isPressed = true;
			}
		}
	}
	else
	{
		device.btn.timer = 0;
		device.btn.isHeld = false;

		if (device.btn.isAcknowledged == true)
		{
			device.btn.isPressed = false;
			device.btn.isAcknowledged = false;
		}
	}
}
/* [] END OF FILE */
