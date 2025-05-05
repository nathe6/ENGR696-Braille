/*
 * GPIOSetup.h
 *
 *  Created on: May 4, 2025
 *      Author: Nathaniel Setiawan, Gregory Aguilar, 
 				Orlean Rallos, Benson Kuang
 */

#ifndef MAIN_GPIOSETUP_H_
#define MAIN_GPIOSETUP_H_

#include <stdio.h>
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

#define BUTTON1 GPIO_NUM_4
#define BUTTON2 GPIO_NUM_5
#define BUTTON3 GPIO_NUM_6

void GPIOSetup(void); // Full Setup TBD in here
#endif /* MAIN_GPIOSETUP_H_ */
