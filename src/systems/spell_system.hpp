#pragma once

#include "game/game.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class collision_event;

	class spell_system : public dawn::system
	{
	public:
		spell_system(game& game, dawn::entity_list& entities);

	protected:
		void update_entity(dawn::entity::ptr entity);

	private:
		void on_collision(const collision_event& event);

		void trigger(dawn::entity::ptr entity);

		game& m_game;
		dawn::entity_list& m_entities;
	};
}
