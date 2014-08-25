#include "player_system.hpp"

#include "components/player_component.hpp"
#include "events/death_event.hpp"


using namespace game;

player_system::player_system(game& game, dawn::entity_list& entities)
:
dawn::system([](dawn::entity::ptr entity)
{
	return entity->has_component<player_component>();
}),
m_game(game),
m_entities(entities)
{
	set_event_handler<death_event>(m_game.get_event_dispatcher(), std::bind(&player_system::on_death, this, std::placeholders::_1, std::placeholders::_2));
}

void player_system::on_death(dawn::entity::ptr entity, const death_event& event)
{
	if(event.entity == entity)
	{
		std::cout << "Player " << entity->get_component<player_component>().id << " died." << std::endl;
		m_entities.remove_entity(entity);
	}
}

void player_system::update_entity(dawn::entity::ptr entity)
{

}
