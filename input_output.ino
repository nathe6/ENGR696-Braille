/*ARDUINO_IDE Version:
This is development code for the ARKS 696 Refreshable display demo piece.
*/

#include <Arduino.h>
#include "FS.h"
#include <LittleFS.h> // LittleFS on ESP32-S3

// Forward declaration
void readFile(fs::FS &fs, const char* path);

void setup() {
  Serial.begin(115200);
  delay(200);

  // If GPIO3 gives trouble on ESP32-S3, try GPIO4 instead
  pinMode(3, OUTPUT);

  // Mount LittleFS (true = format if mount fails)
  if (!LittleFS.begin(true)) {
    Serial.println("LittleFS mount failed");
    while (true) { delay(1000); }
  }

  // Read a file stored on the ESP32's LittleFS, NOT your PC
  readFile(LittleFS, "/numbers.csv");
}

void readFile(fs::FS &fs, const char* path) {
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path, FILE_READ);
  if (!file || file.isDirectory()) {
    Serial.println("Couldn't read the file (missing or is a directory).");
    return;
  }

  Serial.println("- File contents:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void loop() {
  digitalWrite(3, HIGH);
  Serial.println("high");
  delay(100);

  digitalWrite(3, LOW);
  Serial.println("low");
  delay(100);
}