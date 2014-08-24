#pragma once

#include "factories/projectile_factory.hpp"
#include "game/game.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class game;
	class death_system : public dawn::system
	{
	public:
		death_system(game& game, dawn::entity_list& entities);

	protected:
		void update_entity(dawn::entity::ptr entity);

	private:
		game& m_game;
		dawn::entity_list& m_entities;
	};
}
