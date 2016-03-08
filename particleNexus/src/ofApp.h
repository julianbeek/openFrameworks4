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

  ofFbo fbo;

  float time;
  //float birthRate = 1000;
  
  ofxPanel gui;
    ofParameter<float> radius;
    ofParameter<float> maxSpeed;
    ofParameter<float> lifeTime;
    ofParameter<float> rotate;
    ofParameter<float> birthRate;
    ofParameter<float> force;
    ofParameter<float> spinning;
    ofParameter<float> friction;
    Parameters parameters;

  vector<Particle> particles;
    

};


//float radius = 60;
//float maxSpeed = 300;
//float lifeTime = 1.0;
//float rotate = 90;