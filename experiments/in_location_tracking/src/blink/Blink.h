#include <Arduino.h>

class Blink
{
public:
  void init();
  void flash();
  void pulse();

private:
  byte light = LOW;
  long now = millis();
  long last = 0; // max 2,147,483,647 ~ 24.8 days
  float pwm = 0; // max 3.4028235E+38 () 31:sign, 30–23:exponent, 22–0:mantissa
                 // but this will loose accuracy as the count gets higher?
};