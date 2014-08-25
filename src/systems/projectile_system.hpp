#pragma once

#include "game/game.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class collision_event;

	class projectile_system : public dawn::system
	{
	public:
		projectile_system(game& game, dawn::entity_list& entities);

		void update_entity(dawn::entity::ptr entity);

	private:
		void on_collision(dawn::entity::ptr entity, const collision_event& event);

	private:
		game& m_game;
		dawn::entity_list& m_entities;
	};
}
