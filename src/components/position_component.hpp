#pragma once

#include "util/math.hpp"

#include <dawn/ecs/component.hpp>


namespace game
{
	class position_component : public dawn::component
	{
	public:
		position_component(const glm::vec2& position) : position(position) {}
		glm::vec2 position;
	};
}
