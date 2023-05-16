#ifndef PIXEL_H
#define PIXEL_H
class Pixel {
  int r;
  int g;
  int b;
public:
  Pixel();
  Pixel(int, int, int);
  void set(int, int, int);
  void print(std::ostream&);
};
#endif
