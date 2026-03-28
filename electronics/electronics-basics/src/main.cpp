#include <Arduino.h>

long last = 0;
boolean light = false;

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  long now = millis();
  if (now - last > 1000) // every 50ms ~20Hz flash
  {
    light = !light;
    digitalWrite(LED_BUILTIN, light ? HIGH : LOW);
    Serial.print(">led:");
    Serial.println(light);
    last = now;
  }
  delay(10);
}