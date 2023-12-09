#include <chrono>
#include <thread>
#include <iostream>

#include "Vector2d.h"
#include "Simulation.h"
#include "Particle.h"


int main() {
	Simulation simulation {10, 10};
	Particle particle { &simulation, {0, 0} };

	std::cout << "Starting simulation...\n";
	while (true) {
		simulation.update();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	
	return 0;
}
