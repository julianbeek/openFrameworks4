#pragma once

#include "ofMain.h"

#include "Particle.h"

#define DEFAULT_LENGTH 100

class Spring {
 public:
  Spring(Particle* first, Particle* second);

  void update();
  void draw();

  Particle* first;
  Particle* second;

  float length;
};
