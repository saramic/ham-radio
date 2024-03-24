#include <SPI.h>
#include <TFT_eSPI.h>

class Display
{
public:
  void init();
  void drawNeedle(int angle);

private:
  TFT_eSPI tft = TFT_eSPI();
  void drawNeedleWithColor(int angle, uint16_t color);
};