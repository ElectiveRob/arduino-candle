#ifndef Candle_h
#define Candle_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "color.h"

class Candle
{
public:
  bool on;
  int effect;

  // speed of the current effect
  // 1= default speed
  // 2= two times faster
  // ...
  // Not all effects require or make use of the speed
  int speed;
  int r, g, b;
  Candle(Adafruit_NeoPixel& pixels);

  void setRGB(int r, int g, int b);

  void update();
private:
  Color* _color;
  Adafruit_NeoPixel* _pixels;
  unsigned long _prevTime;
  int _delay;
  int _r, _g, _b;
  int _counter;

  void applyEffect();

  void applyCrackling();

  void applyRainbow();

  void applyFade();

  bool delayPassed();

  void wheel(byte pos);

  float getSpeedFactor();
};

#endif
