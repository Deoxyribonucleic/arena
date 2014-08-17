#pragma once

#include <dawn/ecs/component.hpp>


namespace game
{
	class physical_component : public dawn::component
	{
	public:
		physical_component(float x, float y) : x(x), y(y) {}
		float x, y;
	};
}
