#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();
   // void keyPressed(int key);
    
    
    
    ofxPanel gui;
    
    ofParameterGroup particleParams;
    
    Parameters particleUI;
    ofLight light; 

  ofFbo fbo;

  float time;

  Parameters parameters;

  vector<Particle> particles;

};
