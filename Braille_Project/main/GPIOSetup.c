/*
 * GPIOSetup.c
 *
 *  Created on: May 4, 2025
 *      Author: Nathaniel Setiawan, Gregory Aguilar, 
 				Orlean Rallos, Benson Kuang
 */

#include "GPIOSetup.h"
#include "hal/gpio_types.h"

void GPIOSetup(void) {
	
	gpio_sleep_set_direction(BUTTON1, GPIO_MODE_INPUT);
	gpio_sleep_set_direction(BUTTON2, GPIO_MODE_INPUT);
	gpio_sleep_set_direction(BUTTON3, GPIO_MODE_INPUT);
	
	gpio_pullup_en(BUTTON1);
	gpio_pullup_en(BUTTON2);
	gpio_pullup_en(BUTTON3);
	
	gpio_pulldown_dis(BUTTON1);
	gpio_pulldown_dis(BUTTON2);
	gpio_pulldown_dis(BUTTON3);
	
	
} // Full Setup TBD in here