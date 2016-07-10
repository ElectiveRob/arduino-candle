#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "candle.h"
#include "color.h"

Candle::Candle(Adafruit_NeoPixel& pixels)
{
  on = true;
  effect = 0;
  _pixels = &pixels;
  _delay = 0;
  _prevTime = 0;
}

void Candle::setRGB(int r, int g, int b)
{
  this->r = r;
  this->g = g;
  this->b = b;
}

void Candle::update()
{
  _r = r;
  _g = g;
  _b = b;

  if(on)
  {
    this->applyEffect();
  }else{
    _r = _g = _b = 0;
  }

  if(!this->delayPassed()) return;

  // print color for debug
  /*Serial.println("Update color");
  Serial.print("R: ");
  Serial.print(_r);
  Serial.print("G: ");
  Serial.print(_g);
  Serial.print("B: ");
  Serial.print(_b);
  Serial.println("");*/

  _pixels->setPixelColor(0, _pixels->Color(_r,_g,_b));
  _pixels->show();
  unsigned long currentTime = millis();
  _prevTime = currentTime;
}

bool Candle::delayPassed()
{
  unsigned long currentTime = millis();
  if(currentTime - _prevTime > _delay)
    return true;
  return false;
}

void Candle::applyEffect(){
  switch(effect){
    case 1:
      this->applyCrackling();
    break;
    default:
      break;
  }
}

void Candle::applyCrackling(){
  int x = random(300);
  if(x > 200)
  {
    // apply crackling effect
    int alpha = random(50) + 50;
    _r = Color::darker(_r,alpha);
    _g = Color::darker(_g,alpha);
    _b = Color::darker(_b,alpha);
  }
  _delay = random(50) + 150;
}
