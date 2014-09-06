#include "spell_system.hpp"

#include "components/spell_component.hpp"
#include "components/position_component.hpp"
#include "components/orientation_component.hpp"
#include "components/collision_component.hpp"
#include "events/collision_event.hpp"
#include "spells/spell_triggers.hpp"

#include <iostream>


using namespace game;

spell_system::spell_system(game& game, dawn::entity_list& entities)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<spell_component>() && entity->has_component<position_component>();
	}),
	m_game(game),
	m_entities(entities)
{
	m_game.get_event_dispatcher().add_event_handler<collision_event>(
		std::bind(&spell_system::on_collision, this, std::placeholders::_1));
}

void spell_system::update_entity(dawn::entity::ptr entity)
{
}

void spell_system::on_collision(const collision_event& event)
{
	if(event.collider->has_component<spell_component>())
	{
		auto& stage = event.collider->get_component<spell_component>().stage;
		//if(stage.get().trigger_is_enabled())
		{
			std::cout << "Spell collided and triggered" << std::endl;

			std::cout << "Next stage spawned" << std::endl;
			stage.spawn_next(m_entities, event.collider);
		}
	}
}
