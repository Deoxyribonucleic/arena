#pragma once

#include "util/math.hpp"

#include <dawn/time.hpp>

#include <SFML/Graphics.hpp>


namespace game
{
	struct particle
	{
		sf::Color color;
		float size;
		float rotation;
		glm::vec2 position, velocity;
		dawn::time::time_point expire_at;
	};
}
