#pragma once

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>
#include <dawn/ecs/system.hpp>
#include <dawn/time.hpp>


namespace game
{
	class game;
	class collision_system : public dawn::system
	{
	public:
		collision_system(game& game, dawn::entity_list& entities);

	protected:
		void update_entity(dawn::entity::ptr entity);

	private:
		game& m_game;
		dawn::entity_list& m_entities;
	};
}
