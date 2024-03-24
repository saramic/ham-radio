#include <Arduino.h>

#include "blink/Blink.h"

#define LED_BUILTIN 2 // ESP32 equivalent of Arduino 13
#define BOOT_GPIO0 0  // ESP32 boot button

Blink blink;

void switchMode()
{
  blink.switchState();
}

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  // NOTE: FALLING is button depressed, (RISING is button released)
  attachInterrupt(BOOT_GPIO0, switchMode, FALLING); // LOW, HIGHT, CHANGE, FALLING, RISING

  blink.init();
}

void loop()
{
  blink.perform();

  delay(20);
}