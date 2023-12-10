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

	Vector2d cursor { simulation.getWidth() / 2, simulation.getHeight() / 2 };
	while (true) {
		simulation.update();
		simulation.render(cursor);
		
		// (temp) get key state
		if (GetKeyState(VK_LEFT) & 0x8000) {
			--cursor.x;
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			++cursor.x;
		}
		cursor.x = std::max(0, std::min(simulation.getWidth() - 1, cursor.x));
		if (GetKeyState(VK_UP) & 0x8000) {
			--cursor.y;
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			++cursor.y;
		}
		cursor.y = std::max(0, std::min(simulation.getHeight() - 1, cursor.y));
		
		if (GetKeyState(VK_RETURN) & 0x8000) {
			if (!simulation.at(cursor)) {
				Particle* particle = new Particle(&simulation, cursor);
				std::shared_ptr<Particle> ptr { particle };
				particles.push_back(ptr);
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	
	return 0;
}
