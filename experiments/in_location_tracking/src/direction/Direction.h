#include <QMC5883LCompass.h>

class Direction
{
public:
  void init();
  void calibrate(void (*callbackPre)(), void (*callbackStart)(), void (*callbackEnd)());
  int read();

private:
  QMC5883LCompass compass;
};