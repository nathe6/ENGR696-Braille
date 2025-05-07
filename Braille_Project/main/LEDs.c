/*
 * LEDSetup.c
 *
 *  Created on: May 6, 2025
 *      Author: Nathaniel Setiawan
 */

#include "LEDs.h"

void LEDSetup(void) {

  gpio_sleep_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
  ESP_LOGI(TAG, "Configuring RGB LED at GPIO PIN...", LED_PIN);

  led_strip_config_t strip_config = {
    .strip_gpio_num = LED_PIN,
    .max_leds = 1; 
  };

  led_strip_rmt_config_t rmt_config = {
    .resolution_hz = 10 * 1000 * 1000; // 10 MHz setup
    .flags.with_dma = false,
  };

  ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));

  led_strip_clear(led_strip);
  led_strip_set_pixel (led_strip, 0, 255, 255, 255);
  led_strip_refresh (led_strip);

}

void LEDSet (int choice) {

  switch (choice) {
    case 0:
      led_strip_set_pixel (led_strip, 0, 255, 0, 0);
      break;
    case 1:
      led_strip_set_pixel (led_strip, 0, 0, 255, 0);
      break;
    case 2:
      led_strip_set_pixel (led_strip, 0, 0, 0, 255);
      break;
    default:
      printf("Error! Somehow, invalid choice was selected.");
      break;
  }

}
