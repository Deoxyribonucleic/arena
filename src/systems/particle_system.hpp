#pragma once

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class game;
	class particle_system : public dawn::system
	{
	public:
		particle_system(game& game);

	protected:
		void update_entity(dawn::entity::ptr entity);

	private:
		game& m_game;
	};
}
