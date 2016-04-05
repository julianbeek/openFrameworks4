#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
		void mousePressed(int x, int y, int button);
    
    ofVideoGrabber grabber;
    ofxCvColorImage rgbImage;
    ofxCvColorImage hsbImage;
    
    ofxCvGrayscaleImage hue;
    ofxCvGrayscaleImage saturation;
    ofxCvGrayscaleImage brightness;
    
    ofxCvGrayscaleImage filtered;
    
    ofxCvContourFinder contours;
    
    int findHue; 
};
