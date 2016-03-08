#include "ofApp.h"

void ofApp::setup() {
  ofSetFrameRate(20);

  ofSetBackgroundAuto(false);
  ofBackground(ofColor::black);
  ofEnableAlphaBlending();

  rgbaFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
  rgbaFbo.begin();
  ofClear(0, 0, 0, 0);
  rgbaFbo.end();
}

void ofApp::update() {
  if (paused) return;

  // calculate the effects of all Springs
  for (int i = 0; i < springs.size(); i++) {
    springs[i]->update();
  }

  // calculate new positions of Particles
  for (int i = 0; i < particles.size(); i++) {
    particles[i]->update();
  }
}

void ofApp::draw() {
  ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS" + (paused ? " - PAUSED" : ""));

  rgbaFbo.begin();
  ofFill();
  ofSetColor(0, 0, 0, fadeAmount);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

  if (drawParticles) {
    for (int i = 0; i < particles.size(); i++) {
      particles[i]->draw();
    }
  }

  if (drawSprings) {
    for (int i = 0; i < springs.size(); i++) {
      springs[i]->draw();
    }
  }

  rgbaFbo.end();

  rgbaFbo.draw(0, 0);

  if (addingSpring) {
    ofSetColor(ofColor::white);
    ofDrawLine(firstParticle->position, ofPoint(mouseX, mouseY));
  }
}

void ofApp::mousePressed(int x, int y, int button) {
  Particle* insideParticle = findParticle(x, y);

  if (insideParticle != NULL) {
    if (addingSpring) {
      Particle* secondParticle = findParticle(x, y);
      Spring* spring = new Spring(firstParticle, secondParticle);
      springs.push_back(spring);

      addingSpring = false;
    } else {
      addingSpring = true;
      firstParticle = findParticle(x, y);
    }
  } else {
    addParticle(x, y);
  }
}

void ofApp::keyPressed(int key) {
  if (key == 's') {
    drawSprings = !drawSprings;
  } else if (key == 'p') {
    drawParticles = !drawParticles;
  } else if (key == ' ') {
    paused = !paused;
  }
}

void ofApp::addParticle(int x, int y) {
  Particle* particle = new Particle(x, y);
  particles.push_back(particle);
}

Particle* ofApp::findParticle(int x, int y) {
  for (int i = 0; i < particles.size(); i++) {
    Particle* particle = particles[i];
    if (particle->position.distance(ofPoint(x, y)) < particle->radius) {
      return particle;
    }
  }
  return NULL;
}

void ofApp::addSpring(Particle* first, Particle* second) {
  Spring* spring = new Spring(first, second);
  springs.push_back(spring);
}
