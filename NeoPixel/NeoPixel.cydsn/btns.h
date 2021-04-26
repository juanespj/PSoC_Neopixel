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
#include "stdint.h"
#include "stdbool.h"
#include "time.h"

#define BTN_CHECK_MSEC 5  // Read hardware every 5 msec
#define BTN_PRESS_MSEC 50 // Stable time before registering pressed
#define BTN_HOLD_TIME 100000  // Stable time before registering released
#define BTN_TICK_TIME 1
#define FEEDER_TICK 1 //ms

typedef struct BTN_INSTANCE_t
{
	bool isPressed;
	bool isHeld;
	bool isAcknowledged;
	uint32_t timer;
	bool sense;
} BTN_INSTANCE_t;

typedef enum DEV_STATES_t
{
	IDLE,
	RAINBOW,
	EXPLODE,
	THEATER_CHASE,
} DEV_STATES_t;

typedef struct DevState
{
	DEV_STATES_t state;
	DEV_STATES_t prev_state;
	bool new_state;
	uint16_t timer;
	BTN_INSTANCE_t btn;
} DevState;

#ifndef BTNS_H_

bool BTN_getPressed();
bool BTN_getHeld();
void BTN_task(void);
void feeder_task(void);

#else

/** This structure is used to hold the machine state */
extern void BTN_task(void);
extern bool BTN_getPressed();
extern bool BTN_getHeld();
extern void feeder_task(void);
#endif

/* [] END OF FILE */
