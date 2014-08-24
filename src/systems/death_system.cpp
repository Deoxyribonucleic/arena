#include "death_system.hpp"

#include "components/player_component.hpp"
#include "components/position_component.hpp"
#include "components/health_component.hpp"
#include "events/death_event.hpp"
#include "game/game.hpp"

#include <iostream>
#include <string>


using namespace game;

death_system::death_system(game& game, dawn::entity_list& entities)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<health_component>();
	}),
	m_game(game),
	m_entities(entities)
{
}

void death_system::update_entity(dawn::entity::ptr entity)
{
	if(!entity->get_component<health_component>().is_alive())
	{
		std::cout << "Entity " << entity.get() << " died." << std::endl;
		m_game.get_event_dispatcher().notify(death_event(entity, nullptr));
	}
}
