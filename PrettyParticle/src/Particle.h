#pragma once

#include "ofMain.h"

class Particle {
 public:
  static ofImage image;

  ofVec3f position;
  ofVec3f velocity;
  ofVec3f force;

  float friction;
  int alpha;
  bool isAlive;

  Particle();
  virtual ~Particle();

  void setup(float px, float py, float pz, float vx, float vy, float vz);
  void update();
  void draw();

  void resetForce();
  void addForce(float x, float y, float z);
  void addDampingForce();

 protected:
 private:
};

// ofImage Particle::image = ofImage();
