#include "Particle.h"

ofImage Particle::image = ofImage();

Particle::Particle() {
  setup(0, 0, 0, 0, 0, 0);
  friction = ofRandom(0.005f, 0.01f);
}

Particle::~Particle() {}

void Particle::resetForce() {
  force.set(0, 0);
}

void Particle::addForce(float x, float y, float z) {
  force = force + ofVec3f(x, y, z);
}

void Particle::addDampingForce() {
  force = force - velocity * friction;
}

void Particle::setup(float px, float py, float pz, float vx, float vy, float vz) {
  position.set(px, py, pz);
  velocity.set(vx, vy, vz);
  alpha = 255;
  isAlive = true;
}

void Particle::update() {
  if (!isAlive) return;
  velocity = velocity + force;
  position = position + velocity;
}

void Particle::draw() {
  if (!isAlive) return;

  if (velocity.lengthSquared() < .1) {
    alpha -= 1;
    isAlive = (alpha > 0);
  }
  ofSetColor(ofColor::white, alpha);
  image.draw(position.x - 16, position.y - 16, position.z);
}
