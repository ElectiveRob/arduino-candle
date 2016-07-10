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

  bool delayPassed();

  void wheel(byte pos);
};

#endif
