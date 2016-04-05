#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"

#define GRABBER_WIDTH 1024
#define GRABBER_HEIGHT 680

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
        void keyPressed(int key);

        ofVideoGrabber grabber;
        ofxCvHaarFinder haarFinder;
        bool drawBox = true;

        ofImage image;
        bool drawImage = false;
    
    //this holds all of our points
    vector<ofVec3f> points;
    //this keeps track of the center of all the points
    ofVec3f center;
    
    //our camera objects for looking at the scene from multiple perspectives
    ofCamera camera;
    
    //if usecamera is true, we'll turn on the camera view
    bool usecamera;

};
