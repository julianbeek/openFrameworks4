#include "Parameters.h"

Parameters::Parameters() {
  startingPoint = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
}

void Parameters::setup(string name){
    particleParamgroup.setName(name);
    particleParamgroup.add(radius.set("Radius", 0,0,60));
    particleParamgroup.add(maxSpeed.set("Speed", 0,0,300));
    particleParamgroup.add(lifeTime.set("lifeTime", 0,0,1.0));
    particleParamgroup.add(rotate.set("Rotation", 0,0,90));
}


void Parameters::update(){
    //
}

void Parameters::draw(){
    //
}
//  float radius = 60;
//  float maxSpeed = 300;
//  float lifeTime = 1.0;
//  float rotate = 90;