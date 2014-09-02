#include "projectile_element.hpp"

#include "assets/asset_loader.hpp"
#include "components/collision_component.hpp"
#include "components/controller_component.hpp"
#include "components/movement_component.hpp"
#include "components/position_component.hpp"
#include "components/render_component.hpp"
#include "components/player_component.hpp"
#include "components/lifetime_component.hpp"
#include "components/orientation_component.hpp"
#include "components/spell_component.hpp"
#include "components/projectile_component.hpp"


using namespace game;

projectile_element::projectile_element(asset_loader& loader, const sf::Color& color, int count, float spread)
: spell_element(0),
m_loader(loader), m_color(color),
m_count(count), m_spread(spread)
{

}

void projectile_element::spawn(dawn::entity_list& entities, dawn::entity::ptr origin)
{
	assert(origin->has_component<position_component>());
	assert(origin->has_component<orientation_component>());

	for(int i; i<m_count; ++i)
	{
		float angle = -m_spread * (m_count - 1) / 2.0f + i * m_spread;

		dawn::entity::ptr entity(new dawn::entity);
		auto direction = glm::rotate(glm::normalize(origin->get_component<orientation_component>().orientation), glm::radians(angle));

		entity->add_component<position_component>(origin->get_component<position_component>().position + direction * 100.f);
		entity->add_component<movement_component>(direction * 500.f, 0.0, 500.0, 0.0);
		entity->add_component<orientation_component>(direction);
		entity->add_component<render_component>(m_loader.get_sprite(sprites::projectile), m_color);
		entity->add_component<lifetime_component>(std::chrono::seconds(2));
		entity->add_component<collision_component>();
		entity->add_component<projectile_component>();
		entity->add_component<spell_component>(*this);

		entities.add_entity(entity);
	}
}
