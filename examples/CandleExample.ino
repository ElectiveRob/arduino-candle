#include <Adafruit_NeoPixel.h>
#include <candle.h>

#define PIN            13
#define NUMPIXELS      1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
Candle candle = Candle(pixels);

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  candle.setRGB(255,0,0);
  candle.update();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() < 2000)
  {
    // change color
    candle.effect = 0;
    candle.setRGB(0,255,0);
  }else if(millis() < 10000)
  {
    // crackling effect
    candle.setRGB(255,255,0);
    candle.effect = 1;
  }else if(millis() < 20000)
  {
    // rainbow
    candle.speed = 10;
    candle.effect = 2;
  }else if(millis() < 30000)
  {
    // rainbow Fast
    candle.effect = 2;
    candle.speed = 100;
  }else if(millis() < 40000)
  {
    // fade fast
    candle.setRGB(255,0,0);
    candle.effect = 3;
    candle.speed = 100;
  }else if(millis() < 50000)
  {
    // fade slow
    candle.setRGB(255,0,255);
    candle.effect = 3;
    candle.speed = 10;
  }else
  {
    // off
    candle.on = false;
  }
  candle.update();
}
