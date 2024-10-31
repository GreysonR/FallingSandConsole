#ifndef SAND_SIMULATION
#define SAND_SIMULATION

#include <vector>
#include "Particle.h"

class Simulation {
private:
	std::vector<std::vector<Particle*>> world; // world[x][y]; 2d vector of particle pointers
	int width;
	int height;
	int tick; // simulation tick number, aka how many times update has been called; Used to make sure particles are updated in correct order
public:
	Simulation(const int width, const int height);
	Particle*& at(Vector2d position);
	void addParticle(Particle* particle);
	void update();

	int getWidth();
	int getHeight();
	void render(Vector2d& cursor);
};

#endif
