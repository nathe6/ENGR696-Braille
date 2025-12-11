/*
 * GPIOSetup.c
 *
 *  Created on: May 4, 2025
 *      Author: Nathaniel Setiawan, Gregory Aguilar, 
 				Orlean Rallos, Benson Kuang
 */

#include "GPIOSetup.h"
#include "hal/gpio_types.h"

QueueHandle_t interruptQueue1;
QueueHandle_t interruptQueue2;
QueueHandle_t interruptQueue3;

static void IRAM_ATTR gpio_next_handler(void *args) {

    int button1 = (int) args;
    xQueueSendFromISR (interruptQueue1, &button1, NULL);

}

static void IRAM_ATTR gpio_prev_handler(void *args) {

    int button2 = (int) args;
    xQueueSendFromISR (interruptQueue2, &button2, NULL);

}

static void IRAM_ATTR gpio_cycle_handler(void *args) {

    int button3 = (int) args;
    xQueueSendFromISR (interruptQueue3, &button3, NULL);

}

void nextButtonPushed (void *params) {

    int buttonNumber = 0;
    while (true) {

        if (xQueueReceiveFromISR(interruptQueue1, &buttonNumber, portMAX_DELAY)) {

            gpio_next_handler_remove(buttonNumber);

            do {

                vTaskDelay(20 / portTICK_PERIOD_MS);

            } while (gpio_get_level(buttonNumber == 1));

            // Cycle to the next element in the list (alphabet/letter/number via argument call)
            gpio_isr_handler_add(buttonNumber, gpio_next_handler, (void *) buttonNumber);

        }

    }
}

void prevButtonPushed (void *params) {

    int buttonNumber = 0;
    while (true) {

        if (xQueueReceiveFromISR(interruptQueue2, &buttonNumber, portMAX_DELAY)) {

            gpio_next_handler_remove(buttonNumber);

            do {

                vTaskDelay(20 / portTICK_PERIOD_MS);

            } while (gpio_get_level(buttonNumber == 1));

            // Cycle to the next element in the list (alphabet/letter/number via argument call)
            gpio_isr_handler_add(buttonNumber, gpio_prev_handler, (void *) buttonNumber);
            
        }

    }
}

void cycleButtonPushed (void *params) {

    int buttonNumber = 0;
    while (true) {

        if (xQueueReceiveFromISR(interruptQueue3, &buttonNumber, portMAX_DELAY)) {

            gpio_next_handler_remove(buttonNumber);

            do {

                vTaskDelay(20 / portTICK_PERIOD_MS);

            } while (gpio_get_level(buttonNumber == 1));

            // Cycle to the next element in the list (alphabet/letter/number via argument call)
            gpio_isr_handler_add(buttonNumber, gpio_cycle_handler, (void *) buttonNumber);
            
        }

    }
}

void GPIOSetup(void) { // GPIO Setup for the buttons; MCP has its own setup
	
	gpio_sleep_set_direction(BUTTON1, GPIO_MODE_INPUT);
	gpio_sleep_set_direction(BUTTON2, GPIO_MODE_INPUT);
	gpio_sleep_set_direction(BUTTON3, GPIO_MODE_INPUT);
	
	gpio_pullup_en(BUTTON1);
	gpio_pullup_en(BUTTON2);
	gpio_pullup_en(BUTTON3);
	
	gpio_pulldown_dis(BUTTON1);
	gpio_pulldown_dis(BUTTON2);
	gpio_pulldown_dis(BUTTON3);
	
    interruptQueue1 = xQueueCreate(26, sizeof(int));
    xTaskCreate(nextButtonPushed, "nextButtonPushed", 2048, NULL, 1, NULL);
    interruptQueue2 = xQueueCreate(26, sizeof(int));
    xTaskCreate(prevButtonPushed, "nextButtonPushed", 2048, NULL, 2, NULL);
    interruptQueue3 = xQueueCreate(3, sizeof(int));
    xTaskCreate(cycleButtonPushed, "nextButtonPushed", 2048, NULL, 3, NULL);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(BUTTON1, gpio_next_handler, (void *) BUTTON1);
    gpio_isr_handler_add(BUTTON2, gpio_prev_handler, (void *) BUTTON2);
    gpio_isr_handler_add(BUTTON3, gpio_cycle_handler, (void *) BUTTON3);
	
} // Full Setup TBD in here