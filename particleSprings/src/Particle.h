#pragma once

#include "ofMain.h"

class Particle {
 public:
  Particle(int x, int y);

  void update();
  void draw();

  ofPoint position;
  ofVec2f speed;
  int radius;
};
