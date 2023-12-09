#include <vector>
#include <iostream>
#include "Particle.h"
#include "Simulation.h"

using vectorSize = std::vector<Particle*>::size_type;

Simulation::Simulation(const int width, const int height) {
	this->width = width;
	this->height = height;
	this->tick = 0;


	this->world.resize(static_cast<vectorSize>(width));
	for (int i = 0; i < static_cast<int>(world.size()); ++i) {
		this->world.at(i).resize(static_cast<vectorSize>(height));
	}
}
Particle*& Simulation::at(Vector2d position) {
	return this->world[static_cast<vectorSize>(position.x)][static_cast<vectorSize>(position.y)];
}
void Simulation::update() {
	for (std::vector<Particle*> row : this->world) {
		for (Particle* particle : row) {
			if (particle) {
				particle->update(this->tick);
			}
		}
	}
	++this->tick;
}
void Simulation::addParticle(Particle* particle) {
	Particle*& space { this->at(particle->getPosition()) };
	if (!space) {
		space = particle;
	}
}

int Simulation::getWidth() {
	return this->width;
}
int Simulation::getHeight() {
	return this->height;
}
void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
void Simulation::render() {
	int simWidth = this->getWidth();
	int simHeight = this->getHeight();
	clear();
	for (int y = 0; y < simHeight; ++y) {
		for (int x = 0; x < simWidth; ++x) {
			Particle* particle = this->at({ x, y });
			if (particle) {
				std::cout << " # ";
			}
			else {
				std::cout << " . ";
			}
		}
		std::cout << '\n';
	}
}
