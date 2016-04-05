#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "MyCircle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
        void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
    
    ofxBox2d box2d;
    vector<ofxBox2dCircle*> circles;
		
};
