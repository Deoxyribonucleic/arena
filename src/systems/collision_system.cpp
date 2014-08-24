#include "collision_system.hpp"

#include "components/bounding_box_component.hpp"
#include "components/collision_component.hpp"
#include "components/position_component.hpp"
#include "events/collision_event.hpp"
#include "game/game.hpp"

#include <glm/glm.hpp>

#include <functional>
#include <iostream>


using namespace game;

collision_system::collision_system(game& game, dawn::entity_list& entities)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<collision_component>() && entity->has_component<position_component>();
	}),
	m_game(game),
	m_entities(entities)
{
}

void collision_system::update_entity(dawn::entity::ptr entity)
{
	m_entities.foreach(
		[](dawn::entity::ptr entity)
		{
			return entity->has_component<position_component>() && entity->has_component<bounding_box_component>();
		},
		[entity, this](dawn::entity::ptr other_entity)
		{
			if(other_entity->get_component<bounding_box_component>().is_within(
				other_entity->get_component<position_component>().position,
				entity->get_component<position_component>().position))
			{
				m_game.get_event_dispatcher().notify(collision_event(entity, other_entity));
			}
		});
}
