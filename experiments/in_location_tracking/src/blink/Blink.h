#include <Arduino.h>

class Blink {
  public:
    void init();
    void flash();

  private:
    bool light = false;
};