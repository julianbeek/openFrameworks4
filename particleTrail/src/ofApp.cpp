#include "ofApp.h"

void ofApp::setup() {
  ofSetFrameRate(60);
  
    ofSetBackgroundAuto(false);
    ofBackground(ofColor::black);
    ofEnableAlphaBlending();
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);  // GL_greyscale //frame buffer aanmaken
    fbo.begin();
    ofClear(0, 0, 0,0); //leeg maken
    fbo.end();
}

void ofApp::update() {
  ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS");

  // bereken de effecten van alle Springs
  for (int i = 0; i < springs.size(); i++) {
    springs[i]->update();
  }

  // bereken de nieuwe positie & snelheid van de Particles
  for (int i = 0; i < particles.size(); i++) {
    particles[i]->update();
  }
}

void ofApp::draw() {
  ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS");
    fbo.begin();
    
    ofFill();
    ofSetColor(0,0,0, fadeAmount);
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

    fbo.end();
    fbo.draw(0,0);
  // have selected a Particle: draw temporary Spring from Particle to mouse position
  if (selectedFirstParticle) {
    ofSetColor(ofColor::white);
    ofDrawLine(firstParticle->position, ofPoint(mouseX, mouseY));
  }
}

void ofApp::mousePressed(int x, int y, int button) {
  // did we click on an existing particle?
  Particle* clickedParticle = findParticle(x, y);
  if (clickedParticle != NULL) {  // yes, clicked on a particle
    if (selectedFirstParticle) {  // do we already have a Particle selected?
      // yes, so we clicked the second Particle ...
      Particle* secondParticle = clickedParticle;

      // ... create a Spring between the two selected Particles
      Spring* spring = new Spring(firstParticle, secondParticle);
      springs.push_back(spring);
      selectedFirstParticle = false;
    } else {  // no Particle selected yet, so this was the first one
      firstParticle = clickedParticle;
      selectedFirstParticle = true;
    }
  } else {  // we clicked empty space, create a new Particle
    addParticle(x, y);
  }
}

void ofApp::keyPressed(int key) {
  ofLog() << "Pressed " << key << endl;
  if (key == 's') {
    drawSprings = !drawSprings;
  } else if (key == 'p') {
    drawParticles = !drawParticles;
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
