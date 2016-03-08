#include "ofApp.h"

void ofApp::setup() {
  ofBackground(ofColor::black);

  Particle::image.load("particle32.png");
}

void ofApp::update() {
  for (vector<Particle>::iterator it = particles.begin(); it != particles.end();) {
    if (!(*it).isAlive) {
      it = particles.erase(it);
    } else {
      (*it).resetForce();
      (*it).addDampingForce();
      (*it).update();
      it++;
    }
  }

  if (startParticleStream) {
    Particle myParticle;
    float vx = ofRandom(-4, 4);
    float vy = ofRandom(-4, 4);
    float vz = ofRandom(-4, 4);

    myParticle.setup(mouseX, mouseY, 0, vx, vy, vz);
    particles.push_back(myParticle);
  }
}

void ofApp::draw() {
  ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS, " + ofToString(particles.size()) + " particles");
//  cam.begin();

  ofSetColor(ofColor::white);
  for (int i = 0; i < particles.size(); i++) {
    particles[i].draw();
  }
//  cam.end();
}

void ofApp::keyPressed(int key) {
  if (key == 'c') {
    particles.clear();
  } else if (key == 'f') {
    ofToggleFullscreen();
  }
}

void ofApp::mousePressed(int x, int y, int button) {
  startParticleStream = true;
}

void ofApp::mouseReleased(int x, int y, int button) {
  startParticleStream = false;
}
