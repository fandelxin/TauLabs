/**
 ******************************************************************************
 *
 * @file       pios_led.c   
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      LED functions, init, toggle, on & off.
 * @see        The GNU Public License (GPL) Version 3
 * @defgroup   PIOS_LED LED Functions
 * @{
 *
 *****************************************************************************/
/* 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 3 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


/* Project Includes */
#include "pios.h"
#include "openpilot.h"

#if defined(PIOS_INCLUDE_LED)

/* Private Function Prototypes */

DONT_BUILD_IF(PIOS_LED_NUM > 8, piosLedNumTooHigh);

/* Local Variables */
static uint8_t ledStatus;

static inline void PIOS_SetLED(uint32_t led, uint8_t stat)
{
	uint8_t newStatus = ledStatus;

	PIOS_Assert(led < PIOS_LED_NUM);

	uint8_t mask = 1 << led;

	if (stat) {
		newStatus |= mask;
	} else {
		newStatus &= ~mask;
	}

	if (newStatus != ledStatus) {
		ledStatus = newStatus;

		char leds[PIOS_LED_NUM+1];

		uint8_t mask = 1;

		for (int i=0; i<PIOS_LED_NUM; i++) {
			if (newStatus & mask) {
				leds[i] = '*';
			} else {
				leds[i] = '.';
			}

			mask <<= 1;
		}

		leds[PIOS_LED_NUM] = 0;

		printf("PIOS: LEDs: [%s]\n", leds);
	}
}

/**
* Initialises all the LED's
*/
void PIOS_LED_Init(void)
{
}


/**
* Turn on LED
* \param[in] LED LED Name (LED1, LED2)
*/
void PIOS_LED_On(uint32_t led)
{
	PIOS_SetLED(led, 1);
}


/**
* Turn off LED
* \param[in] LED LED Name (LED1, LED2)
*/
void PIOS_LED_Off(uint32_t led)
{
	PIOS_SetLED(led, 0);
}


/**
* Toggle LED on/off
* \param[in] LED LED Name (LED1, LED2)
*/
void PIOS_LED_Toggle(uint32_t led)
{
	PIOS_SetLED(led, ((ledStatus >> led) & 1) ? 0 : 1);
}

#endif
