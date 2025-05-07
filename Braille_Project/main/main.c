#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdbool.h>
#include <unistd.h>
#include "GPIOSetup.h"
#include "driver/gpio.h"
#include "LEDs.h"
// #include "tables.h"

void app_main(void)
{
	// GPIOSetup();
	int caseSelect = 0;
  int letters = 0;
  int numbers = 0;
  int words = 0;
  int mode = 0;

  void GPIOSetup();
  void LEDSetup();

  while (true) {
		
		caseSelect = 0; 
    // Selects which button is pressed
		if (gpio_get_level(BUTTON1) == 1) { 
			caseSelect = 1;                  
		}
		else if (gpio_get_level(BUTTON2)== 1) {
			caseSelect = 2;
		}
		else if (gpio_get_level(BUTTON3) == 1) {
			caseSelect = 3;
		}	
		
		switch(caseSelect) { // Performs the functions needed based on which button is pressed
			case 0:            // Do nothing
				break;
			case 1: // Next letter/number/word
				// nextButton(mode);
        break;
			case 2: // Previous letter/number/word
				// previousButton(mode);
        break;
			case 3: // Switches modes between letters/numbers/words
				// switchMode(mode);
        break;
			default:
				printf("Error: Unknown Input.");
				break;
		  }

    /* Pull up braille cells based on the inputs (i.e. A = {1, 0, 0, 0, 0, 0})
     * Use a separate function w/ alphabet, number, and word tables
     * switch (mode) {
        case 0: 
          // pull up letter (i.e. alphabetCall(letters));
          break;
        case 1:
          // pull up number (i.e. numberCall(numbers));
          break;
        case 2:
          // pull up word (i.e. wordCall(words));
          break;
        default:
          printf("Error, unknown input.");
          break;
      }
     */

    sleep(1);

  }

}
