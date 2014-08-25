#include "projectile_factory.hpp"

#include "assets/asset_loader.hpp"
#include "components/collision_component.hpp"
#include "components/controller_component.hpp"
#include "components/movement_component.hpp"
#include "components/position_component.hpp"
#include "components/render_component.hpp"
#include "components/player_component.hpp"
#include "components/lifetime_component.hpp"
#include "components/orientation_component.hpp"
#include "components/projectile_component.hpp"

#include <cassert>
#include <iostream>


using namespace game;

projectile_factory::projectile_factory(asset_loader& loader)
: m_loader(loader)
{
}

dawn::entity::ptr projectile_factory::create(dawn::entity::ptr shooter, glm::vec2 const& direction)
{
	assert(shooter->has_component<position_component>());

	dawn::entity::ptr entity(new dawn::entity);

	entity->add_component<position_component>(shooter->get_component<position_component>().position + direction * 50.f);
	entity->add_component<movement_component>(direction * 500.f, 0.0, 500.0, 0.0);
	entity->add_component<orientation_component>(direction);
	entity->add_component<render_component>(m_loader.get_sprite(sprites::projectile));
	entity->add_component<lifetime_component>(std::chrono::seconds(2));
	entity->add_component<collision_component>();
	entity->add_component<projectile_component>();

	return entity;
}
