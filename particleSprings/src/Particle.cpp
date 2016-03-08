#include "Particle.h"

#include "ofMain.h"

Particle::Particle(int x, int y) {
  position.set(x, y);
  radius = 40;
}

void Particle::update() {
  position += speed;

  if (position.x < 0 || position.x > ofGetWidth()) {
    speed.x = -speed.x;
  }

  if (position.y < 0 || position.y > ofGetHeight()) {
    speed.y = -speed.y;
  }
}

void Particle::draw() {
  ofSetColor(0, 0, 150, 150);
  ofDrawCircle(position.x, position.y, 40);
}
