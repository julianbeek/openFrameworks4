#include "ofApp.h"


void ofApp::setup() {
    ofSetFrameRate(60);
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
    ofBackground(ofColor::black);
    fbo.end();
    
    time = ofGetElapsedTimef();
    
}

void ofApp::update() {
    float currentTime = ofGetElapsedTimef();
    float elapsedTime = ofClamp(currentTime - time, 0, 0.1);
    
    int i = 0;
    while (i < particles.size() ) {
        if (!particles[i].isAlive) {
            particles.erase(particles.begin() +i);
        } else {
            i++;
        }
    }
    
    
    if (particles.size() < 2000) {
        Particle newParticle(&parameters);
        newParticle.setup();
        particles.push_back(newParticle);
    }
    
    for (int i=0; i < particles.size(); i++) {
        particles[i].update(elapsedTime);
    }
}

void ofApp::draw() {
    ofBackground(ofColor::black);
    
    fbo.begin(); //frame buffer
    
    ofEnableAlphaBlending();
    ofSetColor(ofColor::black, 2);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
    
    for (int i=0; i < particles.size(); i++) {
        particles[i].draw();
    }
    
    fbo.end();
    
    ofSetColor(ofColor::white);
    fbo.draw(0,0);
    
}
