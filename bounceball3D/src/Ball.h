#pragma once

#include "ofMain.h"

#define BOX_MAX 300

class Ball {
 public:
  Ball();

  void setup();
  void update();
  void draw();

  // variables
  ofPoint position;
  ofVec3f speed;

  int radius;
  ofColor color;

 private:
};
