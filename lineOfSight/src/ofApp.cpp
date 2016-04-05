#include "ofApp.h"

void ofApp::setup() {
  ofSetFrameRate(30);
  ofSetVerticalSync(true);
    usecamera = false;
    ofBackgroundGradient(ofColor::white, ofColor::grey);

  // start de video grabber
  grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT);

  // laad de HAAR cascade
  haarFinder.setup("haarcascade_frontalface_default.xml");
  //  haarFinder.setup("hand.xml");
  //  haarFinder.setup("haarcascade_frontalface_default.xml");
  //  haarFinder.setup("haarcascade_mouth.xml");
  //  haarFinder.setup("haarcascade_fullbody.xml");

  //  image.load("eyes.png");
  //  image.load("sunglasses.png");
  //  image.load("kiss.png");
  //  image.load("cheese.png");
}

void ofApp::update() {
  grabber.update();
    
  if (grabber.isFrameNew()) {
    haarFinder.findHaarObjects(grabber.getPixels(), 100, 100);
  }
    
    if(!usecamera){
        ofVec3f sumOfAllPoints(0,0,0);
        for(unsigned int i = 0; i < points.size(); i++){
            points[i].z -= 4;
            sumOfAllPoints += points[i];
        }
        center = sumOfAllPoints / points.size();
    }
    
    
}

void ofApp::draw() {

  //grabber.draw(0, 0);
    
    if(usecamera){
        camera.begin();
    }
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for(unsigned int i = 1; i < points.size(); i++){
        
        //find this point and the next point
        ofVec3f thisPoint = points[i-1];
        ofVec3f nextPoint = points[i];
        
        //get the direction from one to the next.
        //the ribbon should fan out from this direction
        ofVec3f direction = (nextPoint - thisPoint);
        
        //get the distance from one point to the next
        float distance = direction.length();
        
        //get the normalized direction. normalized vectors always have a length of one
        //and are really useful for representing directions as opposed to something with length
        ofVec3f unitDirection = direction.getNormalized();
        
        //find both directions to the left and to the right
        ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
        ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
        
        //use the map function to determine the distance.
        //the longer the distance, the narrower the line.
        //this makes it look a bit like brush strokes
        float thickness = ofMap(distance, 0, 600, 20, 2, true);
        
        //calculate the points to the left and to the right
        //by extending the current point in the direction of left/right by the length
        ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
        ofVec3f rightPoint = thisPoint+toTheRight*thickness;
        
        //add these points to the triangle strip
        mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
        mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
    }
    ofSetColor(ofColor::black);
    	mesh.draw();

  ofNoFill();
  ofSetColor(ofColor::white);
  for (int i = 0; i < haarFinder.blobs.size(); i++) {
    ofRectangle blobBoundingRect = haarFinder.blobs[i].boundingRect;

    if (drawBox) {
      ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
    }

    if (drawImage) {
        // misschien hier de lijnen code???
      //image.draw(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
        if(usecamera){
            float rotateAmount = ofMap(blobBoundingRect.x, 0, ofGetWidth(), 0, 360);
            ofVec3f furthestPoint;
            if (points.size() > 0) {
                furthestPoint = points[0];
            }
            else
            {
                furthestPoint = ofVec3f(blobBoundingRect.x, blobBoundingRect.y, 0);
            }
            
            ofVec3f directionToFurthestPoint = (furthestPoint - center);
            ofVec3f directionToFurthestPointRotated = directionToFurthestPoint.getRotated(rotateAmount, ofVec3f(0,1,0));
            camera.setPosition(center + directionToFurthestPointRotated);
            camera.lookAt(center);
        }
        //otherwise add points like before
        else{
            ofVec3f haarFinder(blobBoundingRect.x,blobBoundingRect.y,0);
            points.push_back(haarFinder);
        }
    }
  }
    
    if(usecamera){
        camera.end();
    }
}

void ofApp::keyPressed(int key) {
  if (key == 'b') {
    drawBox = !drawBox;
  } else if (key == 'i') {
    drawImage = !drawImage;
  }
}
