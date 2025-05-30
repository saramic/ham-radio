#include <Arduino.h>

#include <SPI.h> // required for TFT_eSPI in display/Display.h

#include "blink/Blink.h"
#include "direction/Direction.h"
#include "display/Display.h"

#define LED_BUILTIN 2 // ESP32 equivalent of Arduino 13
#define BOOT_GPIO0 0  // ESP32 boot button

Blink blink;
Direction direction;
Display display;

bool willCalibrate = false;

void switchMode()
{
  blink.switchState();
  willCalibrate = true;
}

void switchOn()
{
  blink.switchOn();
}

void switchOff()
{
  blink.switchOff();
}

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");

  // NOTE: wait for BOOT_GPIO0 to settle to prevent triggering interupt immediately
  delay(500);

  // NOTE: FALLING is button depressed, (RISING is button released)
  attachInterrupt(BOOT_GPIO0, switchMode, FALLING); // LOW, HIGHT, CHANGE, FALLING, RISING

  blink.init();
  direction.init();
  display.init();
}

long now = millis();
long last = millis();
int azimuth = direction.read();

void loop()
{
  blink.perform();
  azimuth = direction.read();
  display.drawNeedle(azimuth);
  now = millis();
  if (now - last > 250)
  {
    Serial.print(">azimuth:");
    Serial.print(azimuth);
    Serial.println();
    last = now;
  }
  if (willCalibrate)
  {
    direction.calibrate(&switchOff, &switchOn, &switchOff);
    willCalibrate = false;
  }
  delay(20);
}