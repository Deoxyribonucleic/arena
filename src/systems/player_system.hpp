#pragma once

#include "game/game.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class death_event;

	class player_system : public dawn::system
	{
	public:
		player_system(game& game, dawn::entity_list& entities);

		void update_entity(dawn::entity::ptr entity);

	private:
		void on_death(dawn::entity::ptr entity, const death_event& event);
		
	private:
		game& m_game;
		dawn::entity_list& m_entities;
	};
}
