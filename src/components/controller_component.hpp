#pragma once

#include <dawn/ecs/component.hpp>


namespace game
{
	class controller_component : public dawn::component
	{
	public:
		controller_component(int p_controller_id) : controller_id(p_controller_id) {}

		int controller_id;
	};
}
