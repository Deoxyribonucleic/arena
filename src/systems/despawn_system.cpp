#include "despawn_system.hpp"

#include "components/lifetime_component.hpp"

#include <dawn/time.hpp>


using namespace game;

despawn_system::despawn_system(dawn::entity_list& entities)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<lifetime_component>();
	}),
	m_entities(entities)
{

}

void despawn_system::update_entity(dawn::entity::ptr entity)
{
	auto& lifetime_info = entity->get_component<lifetime_component>();

	if(dawn::time::clock::now() - lifetime_info.spawn_time > lifetime_info.lifetime)
	{
		m_entities.remove_entity(entity);
	}
}
