#include "Spring.h"

Spring::Spring(Particle* firstParticle, Particle* secondParticle) {
  first = firstParticle;
  second = secondParticle;
  length = DEFAULT_LENGTH;
}

void Spring::update() {
  float distanceBetweenParticles = first->position.distance(second->position);

  ofVec3f direction = second->position - first->position;
  direction.normalize();
  direction *= (distanceBetweenParticles - length) / DEFAULT_LENGTH;
  first->speed += direction;
  second->speed -= direction;
}

void Spring::draw() {
  ofSetColor(255);
  ofDrawLine(first->position, second->position);
}
