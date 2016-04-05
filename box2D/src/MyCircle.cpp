#include "MyCircle.hpp"

MyCircle::MyCircle() {
    setup();
}

void MyCircle::setup() {
    color.r = ofRandom(20, 100);
    color.g = ofRandom(60, 150);
    color.b = ofRandom(200, 255);
}

void MyCircle::draw() {
    float radius = getRadius();
    ofPoint position = getPosition();
    
    ofFill();
    ofSetColor(color);
    ofDrawCircle(position.x, position.y, radius);
}