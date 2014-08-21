#include "projectile_factory.hpp"

#include "assets/asset_loader.hpp"
#include "components/controller_component.hpp"
#include "components/movement_component.hpp"
#include "components/position_component.hpp"
#include "components/render_component.hpp"
#include "components/player_component.hpp"

#include <cassert>


using namespace game;

projectile_factory::projectile_factory(asset_loader& loader)
: m_loader(loader)
{
}

dawn::entity::ptr projectile_factory::create(entity::ptr shooter, glm::vec2 const& direction)
{
	assert(shooter.has_component<position_component());

	dawn::entity::ptr entity(new dawn::entity);

	entity->add_component<position_component>(shooter.get_component<position_component>().position);
	entity->add_component<movement_component>(direction * 1600f, 0.0, 1600.0, 0.0);
	entity->add_component<render_component>(m_loader.get_sprite(sprites::projectile));

	return entity;
}
