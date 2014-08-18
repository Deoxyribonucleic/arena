#pragma once

#include "events/sfml_event.hpp"

#include <dawn/ecs/system.hpp>


namespace game
{
	class game;
	class controller_system : public dawn::system
	{
	public:
		controller_system(game& game);

	protected:
		void update_entity(dawn::entity& entity);

		void on_sfml_event(dawn::entity& entity, const sfml_event& event);
	};
}
