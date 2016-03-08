#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofSimpleApp {
 public:
  void setup();
  void update();
  void draw();
  void keyPressed(int key);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);

  vector<Particle> particles;

  ofEasyCam cam;

  bool startParticleStream = false;
};
