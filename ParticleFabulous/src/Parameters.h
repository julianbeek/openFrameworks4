#pragma once

#include "ofMain.h"

class Parameters {
 public:
  Parameters();
    //virtual ~Parameters();
    void setup(string name);
    void update();
    void draw();

  ofPoint startingPoint;
//  float radius = 60;
//  float maxSpeed = 300;
//  float lifeTime = 1.0;
//  float rotate = 90;
    
    ofParameterGroup particleParamgroup;
    ofParameter<float> radius;
    ofParameter<float> maxSpeed;
    ofParameter<float> lifeTime;
    ofParameter<float> rotate;
};
