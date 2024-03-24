#include "Blink.h"

#define LED_BUILTIN 2 // ESP32 equivalent of Arduino 13
#define FLASH_MS 1000 // 1 second flash rate

void Blink::init()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void Blink::flash()
{
  now = millis();
  if (now - last > FLASH_MS)
  {
    light = light == LOW ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, light);
    Serial.print(">led:");
    Serial.println(light);
    last = now;
  }
}

void Blink::pulse()
{
  analogWrite(LED_BUILTIN, (128 * sin(pwm)) + 128);
  Serial.print(">pwm:");
  Serial.println(pwm);
  Serial.print(">sin:");
  Serial.println(sin(pwm));
  Serial.print(">cos:");
  Serial.println(cos(pwm));
  pwm += 0.1;
}