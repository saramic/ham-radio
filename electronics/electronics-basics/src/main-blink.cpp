#include <Arduino.h>

long last = 0;
boolean light = false;

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  pinMode(LED_BUILTIN, OUTPUT);
  // Optional: set analog reference if needed
  // analogReference(DEFAULT); // 5V on Nano
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
  // Read ADC value from A0
  int adcValue = analogRead(A0);
  // Convert to voltage (assuming 5V reference)
  float voltage = adcValue * (5.0 / 1023.0);
  Serial.print(">A0 voltage: ");
  Serial.print(voltage, 3);
  Serial.println(" V");
  delay(10);
}