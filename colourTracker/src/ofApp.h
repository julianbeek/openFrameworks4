#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define GRABBER_WIDTH 320
#define GRABBER_HEIGHT 240
#define HUE_MARGIN 5

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();

  void mousePressed(int x, int y, int button);
  void keyPressed(int key);

  ofVideoGrabber grabber;

  ofxCvColorImage rgbImage;  // het originele beeld van de camera
  ofxCvColorImage hsvImage;  // HSV versie van het RGB plaatje

  ofxCvGrayscaleImage hue;         // hue-kanaal van 't HSV plaatje
  ofxCvGrayscaleImage saturation;  // saturation-kanaal " "
  ofxCvGrayscaleImage brightness;  // brightness-kanaal " "

  ofxCvGrayscaleImage filtered;  // het hue-kanaal, gefilterd op de selecteerde
    ofxCvGrayscaleImage filteredSecond; 

  ofxCvContourFinder contours;

  int findHue;  // de hue die gebruikt wordt om de contouren te vinden
  int findSecondHue;

  bool showHSVComponents = true;
  bool showFiltered = true;
  bool showContours = true;
};
