#ifndef SAND_SIMULATION
#define SAND_SIMULATION

#include <vector>
#include "Particle.h"

class Simulation {
private:
	std::vector<std::vector<Particle*>> world; // world[x][y]
	int width;
	int height;
	int tick;
public:
	Simulation(const int width, const int height);
	Particle*& at(Vector2d position);
	void addParticle(Particle* particle);
	void update();

	int getWidth();
	int getHeight();
};

#endif
