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
    
    float age; // de leeftijd
    float maxAge; // maximale leeftijd
    bool isAlive; // leeft hij nog
    
    float rotateSpeed;
};
