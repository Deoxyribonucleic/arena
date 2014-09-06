#pragma once

#include "util/math.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/time.hpp>

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>


namespace game
{
	struct particle
	{
		glm::vec3 color;
		float size;
		float rotation;
		float friction;
		glm::vec2 position, velocity;
		dawn::time::duration lifetime;
		dawn::time::time_point expire_at;
		std::weak_ptr<dawn::entity> origin;
	};

	typedef std::vector<particle> particle_list;
}
