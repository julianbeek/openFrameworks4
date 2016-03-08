#include "Ball.h"

Ball::Ball() {}

void Ball::setup() {
  position.x = ofRandom(-BOX_MAX, BOX_MAX);  // give some random positioning
  position.y = ofRandom(-BOX_MAX, BOX_MAX);
  position.z = ofRandom(-BOX_MAX, BOX_MAX);

  speed.x = ofRandom(-20, 20);  // and random speed and direction
  speed.y = ofRandom(-20, 20);
  speed.z = ofRandom(-20, 20);

  radius = 120;

  color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::update() {
  if (position.x < -BOX_MAX) {
    position.x = -BOX_MAX;
    speed.x *= -1;
  } else if (position.x > BOX_MAX) {
    position.x = BOX_MAX;
    speed.x *= -1;
  }

  if (position.y < -BOX_MAX) {
    position.y = -BOX_MAX;
    speed.y *= -1;
  } else if (position.y > BOX_MAX) {
    position.y = BOX_MAX;
    speed.y *= -1;
  }

  if (position.z < -BOX_MAX) {
    position.z = -BOX_MAX;
    speed.z *= -1;
  } else if (position.z > BOX_MAX) {
    position.z = BOX_MAX;
    speed.z *= -1;
  }

  position = position + speed;
}

void Ball::draw() {
  ofSetColor(color);
  ofDrawSphere(position, radius);
}
