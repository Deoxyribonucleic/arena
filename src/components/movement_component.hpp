#pragma once

#include "util/math.hpp"

#include <dawn/ecs/component.hpp>

#include <cassert>
#include <cmath>


namespace game
{
	class movement_component : public dawn::component
	{
	public:
		movement_component(const glm::vec2& velocity, float max_speed, float acceleration, float friction) :
			velocity(velocity),
			max_speed(max_speed),
			acceleration(acceleration),
			friction(friction)
			{}

		glm::vec2 velocity;
		float max_speed;
		float acceleration, friction;

		void accelerate(const glm::vec2& direction, float rate, float max_speed)
		{
			assert(glm::length(direction) != 0.0);

			velocity += glm::normalize(direction) * rate;
			cap_speed(max_speed);
		}

		void decelerate(const glm::vec2& direction, float rate)
		{
			assert(glm::length(direction) != 0.0);

			velocity -= glm::normalize(direction) * std::min(rate, get_speed());
		}

		float get_speed() const
		{
			return glm::length(velocity);
		}

		void cap_speed(float max_speed)
		{
			if(get_speed() > max_speed)
				velocity = glm::normalize(velocity) * max_speed;
		}
	};
}
