#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofBackground(ofColor::black);
    
    box2d.init();
    box2d.setFPS(30);
    box2d.setGravity(0, 0);
    // box2d.createGround();
    box2d.createBounds();
    

    box2d.registerGrabbing();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i<circles.size(); i++){
        circles[i]->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key ==' ') {
        ofxBox2dCircle* circle = new MyCircle();
        circle->setPhysics(3.0, 0.5, 0.1);
        circle->setup(box2d.getWorld(), mouseX, mouseY, ofRandom(20, 60));
        circle->addForce(ofVec2f(ofRandom(-10,10), ofRandom(-20, 0)), 100);
        circles.push_back(circle);
    } else if (key == OF_KEY_RETURN) {
        box2d.setGravity(0,0);
    } else if (key == OF_KEY_UP) {
        box2d.setGravity(0,-5);
    } else if (key ==OF_KEY_DOWN) {
        box2d.setGravity(0,5);
    }
    
}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


