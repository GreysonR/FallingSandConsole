#include <chrono>
#include <thread>
#include <iostream>

#include "Vector2d.h"
#include "Simulation.h"
#include "Particle.h"
#include <memory>
#include <Windows.h>

int main() {
	Simulation simulation {20, 20};
	std::vector<std::shared_ptr<Particle>> particles(4);
	for (int x = 9; x <= 11; ++x) {
		for (int y = 0; y < 6; ++y) {
			Particle* particle = new Particle(&simulation, {x, y});
			std::shared_ptr<Particle> ptr { particle };
			particles.push_back(ptr);
		}
	}

	std::cout << "Starting simulation...\n";
	while (true) {
		simulation.update();
		simulation.render();
		
		// (temp) get key state
		if (GetKeyState(VK_LEFT) & 0x8000) {
			std::cout << "Left\n";
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			std::cout << "Right\n";
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
	
	return 0;
}
