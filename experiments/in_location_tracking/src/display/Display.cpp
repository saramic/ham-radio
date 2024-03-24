#include "display.h"

int oldAngle = 0;
const int mx = TFT_WIDTH / 2;
const int my = TFT_HEIGHT / 2;
const int arrowHeight = min(mx, my);

void Display::init()
{
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(90);
}

void Display::drawNeedleWithColor(int angle, uint16_t color)
{
  long baseWidth = 10;
  long tipX = mx + (int)(sin(angle * DEG_TO_RAD) * arrowHeight);
  long tipY = my + (int)(cos(angle * DEG_TO_RAD) * arrowHeight);
  long baseX1 = mx + (int)(sin((angle + 90) * DEG_TO_RAD) * baseWidth);
  long baseY1 = my + (int)(cos((angle + 90) * DEG_TO_RAD) * baseWidth);
  long baseX2 = mx + (int)(sin((angle - 90) * DEG_TO_RAD) * baseWidth);
  long baseY2 = my + (int)(cos((angle - 90) * DEG_TO_RAD) * baseWidth);
  tft.fillTriangle(tipX, tipY, baseX1, baseY1, baseX2, baseY2, color);
}

void Display::drawNeedle(int angle)
{
  if (abs(angle - oldAngle) > 5)
  {
    drawNeedleWithColor(oldAngle, TFT_BLACK);
    drawNeedleWithColor(oldAngle + 180, TFT_BLACK);
    drawNeedleWithColor(angle, TFT_RED);
    drawNeedleWithColor(angle + 180, TFT_BLUE);
    oldAngle = angle;
  }
}
