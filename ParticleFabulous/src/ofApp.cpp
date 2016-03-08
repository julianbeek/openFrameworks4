#include "ofApp.h"
#include "Parameters.h"

void ofApp::setup() {
  ofSetFrameRate(60);

  fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
  fbo.begin();
  ofBackground(ofColor::black);
  fbo.end();
  
    particleUI.setup("Fabulous"); ///////
    particleParams.add(particleUI.particleParamgroup);
    gui.setup(particleParams);
    

  time = ofGetElapsedTimef();
}

void ofApp::update() {
  float currentTime = ofGetElapsedTimef();
  float elapsedTime = ofClamp(currentTime - time, 0, 0.1);
  time = currentTime;
    
  particleUI.update();

  int i = 0;
  while (i < particles.size()) {
    if (!particles[i].isAlive) {
      particles.erase(particles.begin() + i);
    } else {
      i++;
    }
  }

  if (particles.size() < 2000) {
    Particle newParticle(&parameters);
    newParticle.setup();
    particles.push_back(newParticle);
  }

  for (int i = 0; i < particles.size(); i++) {
    particles[i].update(elapsedTime);
  }
}

void ofApp::draw() {
    light.enable();
    gui.draw();
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
    
        light.disable();
}
