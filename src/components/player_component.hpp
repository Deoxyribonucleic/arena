#pragma once

#include <dawn/ecs/component.hpp>


namespace game
{
	class player_component : public dawn::component
	{
	public:
		player_component(int id) : id(id) {}

		int id;
	};
}
