#pragma once

#include "ofMain.h"

class Parameters {
 public:
  Parameters();

  ofPoint startingPoint;
  float radius;
  float maxSpeed = 100;
  float lifeTime = 1.0;
  float rotate = 90;
};
