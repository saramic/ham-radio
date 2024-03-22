#include <Arduino.h>

#define LED_BUILTIN 2 // ESP32 equivalent of Arduino 13

long last = 0;
boolean light = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("setup");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  long now = millis();
  if (now - last > 1000) // 1 second flash
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
    last = now;
  }
}