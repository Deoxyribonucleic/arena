#pragma once

#include <dawn/ecs/system.hpp>


namespace game
{
	class game;
	class movement_system : public dawn::system
	{
	public:
		movement_system();

	protected:
		void update_entity(dawn::entity& entity);
	};
}
