#include <iostream>
#include <vector>
#include "pixel.h"

const int image_width = 201;
const int image_height = 201;

std::vector<Pixel> image;

int primes[image_width * image_height];

void render();
void compute_primes();

int main() {
  //header for the .ppm file
  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

  image.reserve(image_width * image_height);

  compute_primes();
  
  //position in the image
  int x = image_width / 2;
  int y = image_height / 2;
  //direction the "pen" is moving
  int x_offset = 1; //pattern -> 0 -> -1 -> 0 -> 1
  int y_offset = 0; //pattern -> 1 -> 0 -> -1 -> 0
  //length of time we move in the offset direction
  int rotation_countdown = 1; //a counter
  int rotation_start_value = 1; //the value that the counter will reset to
  bool isIncrementingStartValue = false; //start value increments every other time the counter hits 0
  int num_rotations = 0;

  for(int i = 1; i < image_width * image_height; i++) {
    int n = (x * image_width) + y; //2D point to a 1D array location

    //orange if prime, blue if composite
    Pixel *next_pixel = new Pixel();
    if(primes[i] == 1) {
      next_pixel->set(0, 0, 0);
    } else {
      next_pixel->set(255, 255, 255);
    }
    image.push_back(*next_pixel);

    //move the "pen"
    x += x_offset;
    y += y_offset;
    rotation_countdown--;

    if(rotation_countdown == 0) {
      //Compute new distance before next rotation
      if(isIncrementingStartValue) {
        rotation_countdown = ++rotation_start_value;
        isIncrementingStartValue = false;
      } else {
        rotation_countdown = rotation_start_value;
        isIncrementingStartValue = true;
      }

      //Do the actual rotation. Computed via observed patterns
      y_offset = -x_offset;
      if(num_rotations % 2 == 0) {
        x_offset = 0;
      } else if((num_rotations - 1) % 4 == 0) {
        x_offset = 1;
      } else {
        x_offset = -1;
      }
      num_rotations++;
    }
  }

  //Push the image to the output
  render();
}

void compute_primes() {
  primes[0] = 1;
  primes[1] = 1;
  for(int i = 1; i < image_width * image_height; i++) {
    primes[i] = -1;
  }
  for(int i = 2; i < image_width * image_height; i++) {
    if(primes[i] == -1) {
      primes[i] = 1;
      for(int j = 2; j * i < image_width * image_height; j++) {
        primes[i * j] = 0;
      }
    }
  }
}

void render() {
  for(Pixel i : image) {
    i.print(std::cout);
  }
}
