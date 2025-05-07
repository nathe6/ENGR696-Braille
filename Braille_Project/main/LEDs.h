/*
 * LEDs.h
 *
 *  Created on: May 6, 2025
 *      Author: Nathaniel Setiawan
 */

#ifndef MAIN_LEDS_H_
#define MAIN_LEDS_H_

#include <stdio.h>
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "led_strip.h"

static led_strip_handle_t led_strip;
static const char *TAG = "refreshable_braille_display";

#define LED_PIN 7

void LEDSetup(void);
void LEDSet(int choice);

#endif /* MAIN_LEDS_H_ */