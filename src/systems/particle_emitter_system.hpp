#pragma once

#include "particles/particle.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class game;
	class particle_emitter_system : public dawn::system
	{
	public:
		particle_emitter_system(game& game, particle_list& particles);

	protected:
		void update_entity(dawn::entity::ptr entity);

	private:
		game& m_game;
		particle_list& m_particles;
	};
}
