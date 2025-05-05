#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void app_main(void)
{
	// GPIOSetup();
	int caseSelect = 0;
    while (true) {
		caseSelect = 0;
		// if ()
		
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