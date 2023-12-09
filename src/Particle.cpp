#include "Particle.h"
#include "Vector2d.h"
#include "Simulation.h"
#include <iostream>
#include <algorithm>

Particle::Particle(Simulation* sim, Vector2d pos) : lastUpdateTick { 0 }, position { pos }, simulation { sim } {
	simulation->addParticle(this);
}
bool Particle::withinBounds(Vector2d position) {
	int simWidth = this->simulation->getWidth();
	int simHeight = this->simulation->getHeight();
	return position.x >= 0 && position.x < simWidth && position.y >= 0 && position.y < simHeight;
}
Vector2d& Particle::clampPosition(Vector2d& position) {
	int simWidth = this->simulation->getWidth();
	int simHeight = this->simulation->getHeight();
	position.x = std::max(0, std::min(simWidth - 1, position.x)); // clamp x
	position.y = std::max(0, std::min(simHeight - 1, position.y)); // clamp y
	return position;
}
void Particle::update(int tick) {
	if (this->lastUpdateTick != tick) {
		this->lastUpdateTick = tick;
		Vector2d velocity = { 0, 1 };

		Vector2d nextPosition = this->position + velocity;
		if (!this->withinBounds(nextPosition)) {
			return;
		}
		this->clampPosition(nextPosition);

		if (this->tryMove(nextPosition)) return;
		velocity.x = -1;
		nextPosition = this->position + velocity;
		this->clampPosition(nextPosition);
		if (this->tryMove(nextPosition)) return;

		velocity.x = 1;
		nextPosition = this->position + velocity;
		this->clampPosition(nextPosition);
		if (this->tryMove(nextPosition)) return;
	}
}
bool Particle::tryMove(Vector2d nextPosition) {
	Particle*& space { this->simulation->at(nextPosition) };
	if (space) {
		space->update(this->lastUpdateTick);

		Particle*& spaceB { this->simulation->at(nextPosition) };
		if (spaceB) {
			return false;
		}
	}

	this->setPosition(nextPosition);
	return true;
}
Vector2d& Particle::getPosition() {
	return this->position;
}
void Particle::setPosition(Vector2d position) {
	this->simulation->at(this->position) = nullptr;
	this->position.set(position);
	this->simulation->at(this->position) = this;
}
