#pragma once

#include <dawn/ecs/entity.hpp>
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
		void update_entity(dawn::entity::ptr entity);
		void pre_update();

	private:
		game& m_game;
	};
}
