#pragma once

#include "ofMain.h"

class Parameters {
 public:
  Parameters();

  ofPoint startingPoint;
    ofParameter<float> radius;
    ofParameter<float> maxSpeed;
    ofParameter<float> lifeTime;
    ofParameter<float> rotate;
    ofParameter<float> birthRate;
    ofParameter<float> force;
    ofParameter<float> spinning;
    ofParameter<float> friction;
    ofParameterGroup UIparameter;
    
//    float force = 1000;
//    float spinning = 1000;
//    float friction = 0.05;
};

//float radius = 60;
//float maxSpeed = 300;
//float lifeTime = 1.0;
//float rotate = 90;