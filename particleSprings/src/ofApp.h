#pragma once

#include "ofMain.h"

#include "Particle.h"
#include "Spring.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void mousePressed(int x, int y, int button);

 private:
  void addParticle(int x, int y);
  bool insideParticle(int x, int y);

  void addSpring(Particle* first, Particle* second);

  Particle* findParticle(int x, int y);

  vector<Particle*> particles;
  vector<Spring*> springs;

  bool addingSpring;

  Particle* firstParticle;

  ofFbo rgbaFbo;
  int fadeAmount = 20;

  bool drawParticles = true;
  bool drawSprings = true;
  bool paused = true;
};
