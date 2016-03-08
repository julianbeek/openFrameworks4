#pragma once

#include "ofMain.h"
#include "Parameters.h"

class Particle {
 public:
  Particle(Parameters* parameters);

  void setup();
  void update(float elapsedTime);
  void draw();

  ofPoint randomPointOnCircle(float maxRadius);

  ofPoint position;
  ofVec3f speed;
  bool isAlive;
  float age;
  float maxAge;

  Parameters* param;
};
