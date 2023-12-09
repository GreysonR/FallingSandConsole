#include "Particle.h"
#include "Vector2d.h"
#include "Simulation.h"
#include <iostream>
#include <algorithm>

Particle::Particle(Simulation* sim, Vector2d pos) : lastUpdateTick { 0 }, position { pos }, simulation { sim } {
	simulation->addParticle(this);
}
void Particle::update(int tick) {
	if (this->lastUpdateTick != tick) {
		this->lastUpdateTick = tick;
		Vector2d velocity = { 0, 1 };

		Vector2d nextPosition = this->position + velocity;
		double simWidth = static_cast<double>(this->simulation->getWidth());
		double simHeight = static_cast<double>(this->simulation->getHeight());
		nextPosition.x = std::max(0.0, std::min(simWidth - 1, nextPosition.x)); // clamp x
		nextPosition.y = std::max(0.0, std::min(simHeight - 1, nextPosition.y)); // clamp y
		std::cout << nextPosition.y << '\n';

		Particle*& space { this->simulation->at(nextPosition) };
		if (!space) {
			this->setPosition(nextPosition);
		}
		std::cout << this->simulation->at(this->position)->getPosition() << '\n';
	}
}
Vector2d& Particle::getPosition() {
	return this->position;
}
void Particle::setPosition(Vector2d position) {
	this->simulation->at(this->position) = nullptr;
	this->position.set(position);
	this->simulation->at(this->position) = this;
}
