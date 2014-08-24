#pragma once

#include <dawn/ecs/component.hpp>

#include <glm/glm.hpp>

#include <cassert>
#include <cmath>
#include <iostream>


namespace game
{
	class orientation_component : public dawn::component
	{
	public:
		orientation_component(const glm::vec2& orientation) :
			orientation(orientation)
			{}

		glm::vec2 orientation;

		void set_degrees(float angle)
		{
			orientation.y = glm::sin(angle);
			orientation.x = glm::cos(angle);
		}

		float get_degrees() const
		{
			return glm::degrees(glm::atan(orientation.y, orientation.x));
		}
	};
}
