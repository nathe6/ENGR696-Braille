/* This is an in-development code for an electromagnetic
   actuated refreshable braille display using ESP32-S3
   with addressable RGB LED at GPIO38.
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"

static const char *TAG = "refreshable_braille_display";

#define GPIO_RGB_LED 38

#ifndef CONFIG_BLINK_PERIOD
#define CONFIG_BLINK_PERIOD 1000 // Default 1-second blink
#endif

static uint8_t s_led_state = 0;
static led_strip_handle_t led_strip;

static void blink_led(void)
{
    if (s_led_state) {
        // Set the RGB LED to a dim white (you can change the RGB values)
        led_strip_set_pixel(led_strip, 0, 16, 16, 16);
        led_strip_refresh(led_strip);
    } else {
        // Turn off the RGB LED
        led_strip_clear(led_strip);
    }
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Configuring addressable RGB LED at GPIO%d", GPIO_RGB_LED);

    led_strip_config_t strip_config = {
        .strip_gpio_num = GPIO_RGB_LED,
        .max_leds = 1, // Only one LED on board
    };

    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000, // 10 MHz
        .flags.with_dma = false,
    };

    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));

    led_strip_clear(led_strip);
}

void app_main(void)
{
    configure_led();

    while (1) {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state ? "ON" : "OFF");
        blink_led();
        s_led_state = !s_led_state; // Toggle LED state
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}