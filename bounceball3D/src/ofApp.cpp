#include "ofApp.h"

void ofApp::setup() {
  ofSetFrameRate(60);

  ofBackground(30, 30, 30);

  drawGrid = false;
  drawLight = false;

  ball.setup();
    ball2.setup();

  // plaats een light in de 3d ruimte
  light.setPointLight();
  light.setPosition(BOX_MAX, BOX_MAX, BOX_MAX);
}

void ofApp::update() {
  ball.update();
  ball2.update();

        if (ball.position.distance(ball2.position)<ball.radius){
            ball.speed *=-1;
            ball2.speed *=-1;

        }
    

}

void ofApp::draw() {
  ofEnableDepthTest();
  ofEnableAlphaBlending();

  cam.begin();

  light.enable();

  if (drawGrid) ofDrawGrid(200);
  if (drawLight) light.draw();
  if (drawBox) {
    //    ofNoFill();
    //    ofSetColor(ofColor::white);
    ofSetColor(255, 255, 255, 20);
    ofDrawBox(BOX_MAX * 2, BOX_MAX * 2, BOX_MAX * 2);
    //    ofFill();
  }

  ball.draw();
    ball2.draw();

  light.disable();

  cam.end();

  ofDisableAlphaBlending();
  ofDisableDepthTest();
}

void ofApp::keyPressed(int key) {
  if (key == 'g') {
    drawGrid = !drawGrid;
  } else if (key == 'l') {
    drawLight = !drawLight;
  } else if (key == 'b') {
    drawBox = !drawBox;
  }
}
