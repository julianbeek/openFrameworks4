#include "ofApp.h"

void ofApp::setup() {
  ofBackground(ofColor::black);

  // start de video grabber
  grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT, true);

  // maak de verschillende formaten plaatjes aan
  rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  hsvImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  saturation.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  brightness.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  filteredOne.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  filteredTwo.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
}

void ofApp::update() {
  grabber.update();

  if (grabber.isFrameNew()) {
    // vul het RGB formaat plaatje met 't beeld van de camera
    rgbImage.setFromPixels(grabber.getPixels().getData(), GRABBER_WIDTH, GRABBER_HEIGHT);
    rgbImage.mirror(false, true);

    // maak van het originele RGB formaat plaatje een HSV formaat plaatje
    hsvImage = rgbImage;
    hsvImage.convertRgbToHsv();

    // splits de dir H, S, V kanalen in afzonderlijke plaatjes
    hsvImage.convertToGrayscalePlanarImages(hue, saturation, brightness);

    if (findHueOne != -1) {
      // maak een zwart-wit masker op basis van de geselecteerde Hue (met marge)
      for (int i = 0; i < GRABBER_WIDTH * GRABBER_HEIGHT; i++) {
        if (ofInRange(hue.getPixels()[i], findHueOne - HUE_MARGIN, findHueOne + HUE_MARGIN)) {
          filteredOne.getPixels()[i] = 255;
        } else {
          filteredOne.getPixels()[i] = 0;
        }
      }
      filteredOne.flagImageChanged();
      // laat de contour finder van OpenCV los op het zwart-wit masker, en zoek naar 1 contour
      contoursOne.findContours(filteredOne, 50, GRABBER_WIDTH * GRABBER_HEIGHT / 2, 1, false);
    }

    if (findHueTwo != -1) {
      // maak een zwart-wit masker op basis van de geselecteerde Hue (met marge)
      for (int i = 0; i < GRABBER_WIDTH * GRABBER_HEIGHT; i++) {
        if (ofInRange(hue.getPixels()[i], findHueTwo - HUE_MARGIN, findHueTwo + HUE_MARGIN)) {
          filteredTwo.getPixels()[i] = 255;
        } else {
          filteredTwo.getPixels()[i] = 0;
        }
      }
      filteredTwo.flagImageChanged();
      // laat de tweede contour finder van OpenCV los op het zwart-wit masker, en zoek naar 1 contour
      contoursTwo.findContours(filteredTwo, 50, GRABBER_WIDTH * GRABBER_HEIGHT / 2, 1, false);
    }
  }
}

void ofApp::draw() {
  ofSetColor(ofColor::white);

  // teken de verschillende plaatjes
  rgbImage.draw(640, 0);
  hsvImage.draw(0, 0);

  if (showHSVComponents) {
    hue.draw(0, 240);
    saturation.draw(320, 240);
    brightness.draw(640, 240);
  }

  if (showFiltered) {
    filteredOne.draw(0, 480);
    filteredTwo.draw(320, 480);
    if (showContours) {
      contoursOne.draw(0, 480);
      contoursTwo.draw(320, 480);
    }
  }

  // teken de contouren bovenop het originele RGB plaatje
  if (showContours) {
    contoursOne.draw(640, 0);
    contoursTwo.draw(640, 0);
  }

  // teken een cirkel op het 'middelpunt' van de gevonden contour
  ofSetColor(ofColor::blue, 100);
  ofFill();
  for (int i = 0; i < contoursOne.nBlobs; i++) {
    ofDrawCircle(contoursOne.blobs[i].centroid.x + 640, contoursOne.blobs[i].centroid.y, 20);
  }
  ofSetColor(ofColor::red, 100);
  for (int i = 0; i < contoursTwo.nBlobs; i++) {
    ofDrawCircle(contoursTwo.blobs[i].centroid.x + 640, contoursTwo.blobs[i].centroid.y, 20);
  }
}

void ofApp::keyPressed(int key) {
  if (key == 'h') {
    showHSVComponents = !showHSVComponents;
  } else if (key == 'f') {
    showFiltered = !showFiltered;
  } else if (key == 'c') {
    showContours = !showContours;
  }
}

void ofApp::mousePressed(int x, int y, int button) {
  // in het HSV plaatje, selecteer een kleur om een contour op te zoeken
  if (button == OF_MOUSE_BUTTON_LEFT) {
    findHueOne = hue.getPixels()[y * GRABBER_WIDTH + x];
  } else if (button == OF_MOUSE_BUTTON_RIGHT) {
    findHueTwo = hue.getPixels()[y * GRABBER_WIDTH + x];
  }
}
