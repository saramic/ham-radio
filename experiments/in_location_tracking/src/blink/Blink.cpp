#include "Blink.h"

#define LED_BUILTIN 2 // ESP32 equivalent of Arduino 13

void Blink::init()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void Blink::flash()
{
  if (light)
  {
    light = false;
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print(">led:");
    Serial.println(0);
  }
  else
  {
    light = true;
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print(">led:");
    Serial.println(1);
  }
}