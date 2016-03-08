#include "Spring.h"

Spring::Spring(Particle* firstParticle, Particle* secondParticle) {
  first = firstParticle;
  second = secondParticle;
  length = DEFAULT_LENGTH;
}

void Spring::draw() {
  ofSetColor(ofColor::white);
  ofDrawLine(first->position, second->position);
}

void Spring::update() {
  float distance = first->position.distance(second->position);

  ofVec3f acceleration = second->position - first->position;
  acceleration.normalize();
  acceleration *= (distance - length) / DEFAULT_LENGTH;

  first->speed += acceleration;
  second->speed -= acceleration;
}
