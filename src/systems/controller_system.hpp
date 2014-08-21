#pragma once

#include <dawn/ecs/system.hpp>
#include <dawn/time.hpp>


namespace game
{
	class game;
	class controller_system : public dawn::system
	{
	public:
		controller_system(game& game);

	protected:
		void update_entity(dawn::entity& entity);
		void pre_update();

	private:
		game& m_game;
	};
}
