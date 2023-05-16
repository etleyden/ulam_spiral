#include <iostream>
#include "pixel.h"

Pixel::Pixel() {
  r = 0; g = 0; b = 0;
}
Pixel::Pixel(int red, int green, int blue) {
  r = red;
  g = green;
  b = blue;
}
void Pixel::print(std::ostream &out) {
  out << r << " " << g << " " << b << "\n";
}
void Pixel::set(int red, int green, int blue) {
  r = red;
  g = green;
  b = blue;
}
