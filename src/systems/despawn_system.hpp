#pragma once

#include "factories/projectile_factory.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>
#include <dawn/ecs/system.hpp>


namespace game
{
	class game;
	class despawn_system : public dawn::system
	{
	public:
		despawn_system(dawn::entity_list& entities);

	protected:
		void update_entity(dawn::entity::ptr entity);

	private:
		dawn::entity_list& m_entities;
	};
}
