#include <Arduino.h>
#include "driver/adc.h"

#define LED_BUILTIN 2 // ESP32 equivalent of Arduino 13

long last = 0;
boolean light = false;
uint32_t adc1_ch0_raw = 0;
uint32_t adc1_ch3_raw = 0;
uint32_t adc1_ch6_raw = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  pinMode(LED_BUILTIN, OUTPUT);

  adc1_config_width(ADC_WIDTH_BIT_12);
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_12);
}

void loop()
{
  long now = millis();
  if (now - last > 50) // every 50ms ~20Hz flash
  {
    light = !light;
    digitalWrite(LED_BUILTIN, light ? HIGH : LOW);
    Serial.print(">led:");
    Serial.println(light);
    last = now;
  }
  adc1_ch0_raw = adc1_get_raw(ADC1_CHANNEL_0); // GPIO36
  adc1_ch3_raw = adc1_get_raw(ADC1_CHANNEL_3); // GPIO39
  adc1_ch6_raw = adc1_get_raw(ADC1_CHANNEL_6); // GPIO34
  Serial.print(">adc1_ch0_raw:");
  Serial.println(adc1_ch0_raw);
  Serial.print(">adc1_ch3_raw:");
  Serial.println(adc1_ch3_raw);
  Serial.print(">adc1_ch6_raw:");
  Serial.println(adc1_ch6_raw);
  delay(10);
}