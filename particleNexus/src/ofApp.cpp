#include "ofApp.h"

void ofApp::setup() {
  ofSetFrameRate(60);

  fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
  fbo.begin();
  ofBackground(ofColor::black);
  fbo.end();

  time = ofGetElapsedTimef();
    
    gui.setup("Settings");
    gui.add(radius.set("Radius", 20,0,120));
    gui.add(maxSpeed.set("Speed", 500,0,1000));
    gui.add(lifeTime.set("Life time", 1.0,0,1.0));
    gui.add(rotate.set("Rotation", 180,0,360));
    gui.add(birthRate.set("Amount", 100,100,1000));
    gui.add(force.set("Force", 1000,0,1000));
    gui.add(spinning.set("Spin", 1000,0,1000));
    gui.add(friction.set("Friction",0.05,0,0.05));
    
}

void ofApp::update() {
    parameters.radius = radius;
    parameters.maxSpeed = maxSpeed;
    parameters.lifeTime = lifeTime;
    parameters.rotate = rotate;
    parameters.birthRate = birthRate;
    parameters.force = force;
    parameters.spinning = spinning;
    parameters.friction = friction;
    
  float currentTime = ofGetElapsedTimef();
  float elapsedTime = ofClamp(currentTime - time, 0, 0.1);
  time = currentTime;

  int i = 0;
  while (i < particles.size()) {
    if (!particles[i].isAlive) {
      particles.erase(particles.begin() + i);
    } else {
      i++;
    }
  }
    
    int newParticles = birthRate * elapsedTime;
    for (int i=0; i<newParticles; i++){
    Particle newParticle(&parameters);
    newParticle.setup();
    particles.push_back(newParticle);
  }

  for (int i = 0; i < particles.size(); i++) {
    particles[i].update(elapsedTime);
  }
}

void ofApp::draw() {
  ofBackground(ofColor::black);

  fbo.begin();

  ofEnableAlphaBlending();
  ofSetColor(ofColor::black, 2);
  ofFill();
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  ofDisableAlphaBlending();

  ofFill();
  ofEnableSmoothing();
  for (int i = 0; i < particles.size(); i++) {
    particles[i].draw();
  }

  fbo.end();

  ofSetColor(ofColor::white);
  fbo.draw(0, 0);
    
    gui.draw();
}
