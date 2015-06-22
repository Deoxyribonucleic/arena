#include "projectile_system.hpp"

#include "components/projectile_component.hpp"
#include "components/health_component.hpp"
#include "events/collision_event.hpp"


using namespace game;

projectile_system::projectile_system(game& game, dawn::entity_list& entities)
:
dawn::system([](dawn::entity::ptr entity)
{
	return entity->has_component<projectile_component>();
}),
m_game(game),
m_entities(entities)
{
	set_event_handler<collision_event>(m_game.get_event_dispatcher(), std::bind(&projectile_system::on_collision, this, std::placeholders::_1, std::placeholders::_2));
}

void projectile_system::on_collision(dawn::entity::ptr entity, const collision_event& event)
{
	if(event.collider == entity)
	{
		if(event.collidee->has_component<health_component>())
			event.collidee->get_component<health_component>().health -= 5;

		m_entities.remove_entity(entity);
	}

}

void projectile_system::update_entity(dawn::entity::ptr entity)
{

}
