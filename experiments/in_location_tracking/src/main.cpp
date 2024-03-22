#include <Arduino.h>

#include "blink/Blink.h"

Blink blink;

long last = 0;
boolean light = false;

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  blink.init();
}

void loop()
{
  long now = millis();
  if (now - last > 1000) // 1 second flash
  {
    blink.flash();
    last = now;
  }
  delay(20);
}