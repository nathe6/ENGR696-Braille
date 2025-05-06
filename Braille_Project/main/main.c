#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "GPIOSetup.h"
#include "driver/gpio.h"

void app_main(void)
{
	// GPIOSetup();
	int caseSelect = 0;
    while (true) {
		
		void GPIOSetup();
		caseSelect = 0;
		if (gpio_get_level(BUTTON1) == 1) {
			caseSelect = 1;
		}
		else if (gpio_get_level(BUTTON2)== 1) {
			caseSelect = 2;
		}
		else if (gpio_get_level(BUTTON3) == 1) {
			caseSelect = 3;
		}	
		
		switch(caseSelect) {
			case 0: 
				break;
			case 1:
				// nextButton();
			case 2: 
				// previousButton();
			case 3:
				// switchMode();
			default:
				printf("Error: Unknown Input.");
				break;
		}
        sleep(1);
    }
}