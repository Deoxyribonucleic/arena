#pragma once

#include <dawn/ecs/component.hpp>


namespace game
{
	class position_component : public dawn::component
	{
	public:
		position_component(float x, float y) : x(x), y(y) {}
		float x, y;
	};
}
