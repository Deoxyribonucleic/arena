#pragma once

#include <dawn/ecs/component.hpp>

#include <glm/glm.hpp>

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

		void accelerate(const glm::vec2& direction)
		{
			assert(glm::length(direction) != 0.0);

			velocity += glm::normalize(direction) * acceleration;
			cap_speed();
		}

		void decelerate(const glm::vec2& direction, float amount)
		{
			assert(glm::length(direction) != 0.0);

			velocity -= glm::normalize(direction) * std::min(amount, get_speed());
			cap_speed();
		}

		float get_speed() const
		{
			return glm::length(velocity);
		}

		void cap_speed()
		{
			if(get_speed() > max_speed)
				velocity = glm::normalize(velocity) * max_speed;
		}
	};
}
