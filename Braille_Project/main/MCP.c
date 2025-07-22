/*
 * MCP.c
 *
 *  Created on: Jul 8, 2025
 *      Author: Nathaniel
 */
 
#include "MCP.h"
 
// Choose A or B for pin mode configuration
char bus = 'A'; // Change to 'B' to use GPIOB

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Initializing MCP23017...");

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!mcp.begin_I2C()) {
    Serial.println("MCP23017 not found. Check connections.");
    while (1);
  }

  Serial.println("MCP23017 found.");

  // Set pins 0-7 of selected GPIO bank as OUTPUT
  for (uint8_t i = 0; i < 8; i++) {
    if (bus == 'A') {
      mcp.pinMode(i, OUTPUT);        // GPIOA pins 0-7
    } else if (bus == 'B') {
      mcp.pinMode(i + 8, OUTPUT);    // GPIOB pins 8-15
    }
	delay(100);
  }

}
