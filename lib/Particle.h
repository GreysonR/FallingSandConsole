#ifndef SAND_SIMULATION_PARTICLE
#define SAND_SIMULATION_PARTICLE

#include "Vector2d.h"

class Simulation;

class Particle {
protected:
	int lastUpdateTick;
	Vector2d position;
	Simulation* simulation;
	bool tryMove(Vector2d nextPosition);
	Vector2d& clampPosition(Vector2d& position);
	bool withinBounds(Vector2d position);
public:
	Particle(Simulation* sim, Vector2d pos);
	void update(int tick);
	Vector2d& getPosition();
	void setPosition(Vector2d position);
};

#endif
