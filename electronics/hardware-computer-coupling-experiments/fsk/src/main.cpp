#include <Arduino.h>
#include "driver/adc.h"

#define FSK_PIN 2 // ESP32 equivalent of Arduino 13
const int FSK_FREQ_1 = 1200; // Hz for '1'
const int FSK_FREQ_0 = 2200; // Hz for '0'
const float FSK_BIT_DURATION = 0.2; // seconds per bit
const char *FSK_BITS = "1011001"; // Example bit sequence

void fsk_send_bit(char bit) {
  int freq = (bit == '1') ? FSK_FREQ_1 : FSK_FREQ_0;
  int half_period_us = 1000000 / (2 * freq);
  unsigned long cycles = freq * FSK_BIT_DURATION;
  for (unsigned long i = 0; i < cycles; i++) {
    digitalWrite(FSK_PIN, HIGH);
    delayMicroseconds(half_period_us);
    digitalWrite(FSK_PIN, LOW);
    delayMicroseconds(half_period_us);
  }
}

void fsk_send_sequence(const char *bits) {
  for (int i = 0; bits[i] != '\0'; i++) {
    fsk_send_bit(bits[i]);
    delay(10); // Short gap between bits
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  pinMode(FSK_PIN, OUTPUT);
}

void loop()
{
  // Output FSK sequence every 2 seconds
  static unsigned long last_fsk = 0;
  if (millis() - last_fsk > 2000) {
    fsk_send_sequence(FSK_BITS);
    last_fsk = millis();
  }
  delay(10);
}