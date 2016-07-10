#include "color.h"

int Color::darker(int c, int alpha)
{
  float a = alpha / 100.f;
  return c * a;
}
