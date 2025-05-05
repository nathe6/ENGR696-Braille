/*
 * GPIOSetup.c
 *
 *  Created on: May 4, 2025
 *      Author: Nathaniel Setiawan, Gregory Aguilar, 
 				Orlean Rallos, Benson Kuang
 */

#include "GPIOSetup.h"

void GPIOSetup(void) {
	
	gpio_pullup_en(BUTTON1);
	gpio_pullup_en(BUTTON2);
	gpio_pullup_en(BUTTON3);
} // Full Setup TBD in here