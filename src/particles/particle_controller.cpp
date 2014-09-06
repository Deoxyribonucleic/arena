#include "particle_controller.hpp"


using namespace game;

void particle_controller::update(float delta_time, particle_list& particles)
{
	auto now = dawn::time::clock::now();
	
	for(int i = particles.size() - 1; i >= 0; --i)
	{
		auto& particle = particles[i];

		if(now > particle.expire_at)
		{
			particles.erase(particles.begin() + i);
			continue;
		}

		particle.position += particle.velocity * delta_time;

		if(glm::length(particle.velocity) != 0.0)
			particle.velocity -= glm::normalize(particle.velocity) * std::min(particle.friction * delta_time, glm::length(particle.velocity));
	}
}
