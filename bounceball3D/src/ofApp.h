#pragma once

#include "ofMain.h"

#include "Ball.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();
  void keyPressed(int key);

  Ball ball;
    
    Ball ball2;

  ofLight light;

  bool drawGrid;
  bool drawLight;
  bool drawBox;

  ofEasyCam cam;
};
