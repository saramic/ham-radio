#include "Blink.h"

#define LED_BUILTIN 2 // ESP32 equivalent of Arduino 13
#define FLASH_MS 1000 // 1 second flash rate

#define DEBUG 0

void Blink::init()
{
  // Initialize channels
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(0, 4000, 8); // 12 kHz PWM, 8-bit resolution
  setupPinMode();
}

void Blink::switchState()
{
  state++;
  setupPinMode();
}

void Blink::perform()
{
  (state & 0x1) ?  pulse() : flash();
}

void Blink::flash()
{
  now = millis();
  if (now - last > FLASH_MS)
  {
    light = light == LOW ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, light);
    if (DEBUG)
    {
      Serial.print(">led:");
      Serial.println(light);
    }
    last = now;
  }
}

void Blink::pulse()
{
  // analogWrite(LED_BUILTIN, (128 * sin(pwm)) + 128);
  ledcWrite(0, (128 * sin(pwm)) + 128);
  if (DEBUG)
  {
    Serial.print(">pwm:");
    Serial.println(pwm);
    Serial.print(">sin:");
    Serial.println(sin(pwm));
    Serial.print(">cos:");
    Serial.println(cos(pwm));
  }
  pwm += 0.1;
}

void Blink::switchOn()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void Blink::switchOff()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void Blink::setupPinMode()
{
  if(state & 0x1)
  {
    ledcAttachPin(LED_BUILTIN, 0);
  }
  else
  {
    pinMode(LED_BUILTIN, OUTPUT);
  }
}