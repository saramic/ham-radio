#include <Arduino.h>

// This code toggles pin 8 (PORTB0) as fast as possible using direct port
// manipulation. resulting in a small radio frequency signal on pin D8 at 8MHz
// detactable by the tinySA spectrum analyzer.
void setup() {
  // Set pin 8 (PORTB0) as output
  DDRB |= (1 << DDB0);
}

void loop() {
  // Toggle pin 8 as fast as possible
  PINB = (1 << PINB0);
}